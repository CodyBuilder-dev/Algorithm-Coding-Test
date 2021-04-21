"""
제목 : 길 찾기 게임

아이디어 : 트리에 원소를 넣는 법을 알아낸 후, 순회하면 된다
(1) 트리에 원소를 넣는 법
- 힙에 원소를 넣듯이 자식에서부터 넣는다? -> No
- 루트에서부터 아래로 내려가며 넣는다? -> Yes
    - 누가 루트인지는 어떻게 아는데? -> 정렬
- 트리를 자료구조로 나타낼 것인가? -> Yes
    -  어떤 자료구조로 나타낼 것인가? -> 트리 클래스를 만들자

(2) 전위순회하는 법
- 도달한다
- 방문리스트에 넣는다
- 왼쪽에 대해 재귀
- 오른쪽에 대해 재귀
(3) 후위순회 하는 법
- 도달한다
- 왼쪽에 대해 재귀
- 오른족에 대해 재귀

결과 : 런타임에러
-> 재귀 해제
"""
import sys
sys.setrecursionlimit(1001)

class Node:
    def __init__(self,idx,x,y):
        self.idx = idx
        self.x,self.y = x,y
        self.left = None
        self.right = None

def traverse_pre(root,visited):
    visited.append(root.idx)

    if root.left:
        traverse_pre(root.left,visited)
    if root.right:
        traverse_pre(root.right,visited)

def traverse_post(root,visited):

    if root.left:
        traverse_post(root.left,visited)
    if root.right:
        traverse_post(root.right,visited)
    visited.append(root.idx)

def solution(nodeinfo):
    nodeinfo = [v+[i] for i,v in enumerate(nodeinfo,start=1)]
    nodeinfo = sorted(nodeinfo,key = lambda x:(-x[1],x[0]))

    root = Node(nodeinfo[0][2],nodeinfo[0][0],nodeinfo[0][1])
    # 트리에 원소 삽입
    for node in nodeinfo[1:]:

        current = root
        prev = None
        while current:
            if node[0] < current.x:
                prev = current
                current = current.left
            else:
                prev = current
                current = current.right

        if node[0] < prev.x:
            prev.left = Node(node[2],node[0],node[1])
        else:
            prev.right = Node(node[2],node[0], node[1])

    # 트리 순회
    visited_pre =[]
    traverse_pre(root,visited_pre)

    visited_post = []
    traverse_post(root, visited_post)
    return [visited_pre,visited_post]



print(solution([[5,3],[11,5],[13,3],[3,5],[6,1],[1,3],[8,6],[7,2],[2,2]]))
