"""
제목 : 표 편집

아이디어 : 원하는 요구사항에 가장 잘 맞는 자료구조를 선택해야 한다
- 요구사항
    - 위 아래로 탐색이 쉬워야 한다
    - 삽입과 삭제가 쉬워야 한다
- 자료구조
    - 배열을 쓰면 탐색은 쉽지만, 삽입과 삭제가 매우 어려워진다
        - 삽입삭제에 시간복잡도가 크다
        - 삽입삭제시 인덱스의 처리가 너무 어렵다
    - 어차피 선형구조로만 움직이고, 삽입과 삭제가 쉬워야 하므로 더블 링크드 리스트가 좋다
    - 링크드 리스트의 배열?
        - 포인터가 왔다갔다 하므로 더 불편하다
- 구현
    - U,D : 포인터에서 while문을 이용해 x번 이동한다
        - 단, 더 갈곳이 없으면 멈춘다
    - C :
        - 포인터의 링크드리스트를 없앤다
        - 업어진 링크드 리스트는, 스택에 별도로 저장한다
        - 남은 링크드리스트끼리 연결하고, 그 다음을 현재로 삼는다
    - Z :
        - 스택의 가장 위쪽에 있는 링크드 리스트를 꺼낸다
        - 해당 링크드 리스트의 next와 prev를 찾아 연결한다
    - 최종 판정
        - 각 노드는 최초 부여된 인덱스를 가지고 있다
        - 그걸 바탕으로 OX판정

"""
class Node:
    def __init__(self,idx):
        self.idx = idx
        self.prev = None
        self.next = None
        self.deleted = False

def solution(n, k, cmd):
    nodes = [Node(i) for i in range(n)]
    for i in range(n):
        if i == 0:
            nodes[i].next = nodes[i + 1]
        if i == n-1:
            nodes[i].prev = nodes[i - 1]
        else:
            nodes[i].prev = nodes[i - 1]
            nodes[i].next = nodes[i + 1]

    now = nodes[k]
    garbage = []
    for c in cmd:
        if c[0] == 'U':
            x = int(c.split()[1])
            i = 0
            while i < x and now.prev:
                now = now.prev
                i += 1
        if c[0] == 'D':
            x = int(c.split()[1])
            i = 0
            while i < x and now.next :
                now = now.next
                i += 1
        if c[0] == 'C':
            now.deleted = True
            garbage.append(now)
            if now.prev:
                now.prev.next = now.next
            if now.next:
                now.next.prev = now.prev

            now = now.next if now.next else now.prev

        if c[0] == 'Z':
            temp = garbage.pop()
            temp.deleted = False
            if temp.next:
                temp.next.prev = temp
            if temp.prev:
                temp.prev.next = temp


    return ''.join(["X" if node.deleted else "O" for node in nodes])



print(solution(8,2,["D 2","C","U 3","C","D 4","C","U 2","Z","Z"]))
print(solution(8,2,["D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"]))