"""
제목 : 네트워크

아이디어 : 유니온-파인드
- 네트워크 1개를 집합 1개로 본다면, 같은 집합에 속한 원소를 찾아내는 유니온-파인드를 적용할 수 있다
- 1번 노드부터 N번 노드까지 순차적으로 검사한다
    - 각 노드의 인접 노드들을 모두 유니온으로 묶는다
- 최종적으로 유니온의 개수를 센다

구현 : 유니온 파인드를 구현한다
(1) 유니온 함수와 파인드 함수 구현
-노드 : parent 필드를 갖는 클래스
    - parent가 없을 경우 None으로 비워둘 것인가? 자기자신으로 할 것인가?
    - 둘다 가능하지만, 마지막에 개수를 셀 때 다르게 처리해야 한다

-파인드 : 노드를 넣었을 때 루트를 반환함
    - 부모의 기본값을 None으로 한 경우, 탈출조건은 None일 때
    - 부모의 기본값을 자기 자신으로 한 경우, 탈출 조건은 자기자신일때
        - 탈출 조건이 없으면 무한재귀에 걸린다!

-유니온 : 두 노드를 넣어 루트가 다르면 합침

(2) 유니온의 개수를 세려면, 유니온을 어딘가 저장해야 한다
- 모든 노드들에 대해 find를 수행한 결과물로부터 판단한다
    - 부모의 기본값을 None으로 한 경우, 개수를 셀 때 find의 결과가 none인 노드(루트)개수를 세어야 함
    - 부모의 기본값을 자기자신으로 한 경우, 그냥 find수행한 결과 집합의 원소 개수를 세면 됨
"""


class Node:
    def __init__(self):
        self.parent = self  # 자기 자신을 부모로 가진다


def union(left, right):
    left_root = find(left)
    right_root = find(right)
    if left_root != right_root:
        left_root.parent = right_root


def find(child):
    if child.parent == child:  # 탈출조건을 걸어줘야 한다
        return child
    return find(child.parent)


def solution(n, computers):
    node_list = [Node() for _ in range(len(computers))]

    for i in range(len(computers)):
        for j, v in enumerate(computers[i]):
            if v:
                computers[i][j] = 0
                computers[j][i] = 0
                if i != j:
                    union(node_list[i], node_list[j])

    # 모든 노드에 대해 find를 적용해 루트를 찾은 후 루트의 개수 반환
    return len(set(map(find, node_list)))

# 테스트 케이스
# print(solution(3,[[1, 1, 0], [1, 1, 0], [0, 0, 1]]),2)
# print(solution(3,[[1, 1, 0], [1, 1, 1], [0, 1, 1]]),1)
# print(solution(1,[[1]]))
# print(solution(3,[[1, 1, 1], [1, 1, 1], [1, 1, 1]]))
# print(solution(4,[[1,1,0,0],[1,1,0,1],[0,0,1,1],[0,1,1,1]]))
print(solution(6,[[1, 0, 1, 1, 0, 0], [0, 1, 0, 0, 1, 1], [1, 0, 1, 1, 1, 1], [1, 0, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1]]))

# 9번 테스트케이스 반례
print(solution(5, [[1, 0, 0, 0, 0], [0, 1, 0, 0, 1], [0, 0, 1, 0, 1], [0, 0, 0, 1, 1], [1, 0, 0, 0, 1]]),1)