"""
제목 : 네트워크

아이디어 : 유니온 파인드
- 부모 배열을 이용한 유니온 파인드
"""


def solution(n, computers):
    parent = [x for x in range(n)]

    def find(x):
        if parent[x] == x:
            return x
        # x -> y ->r로 진행된다고 하면 x,y의 부모가 모두 r로 갱신된다
        parent[x] = find(parent[x])
        return parent[x]

    def union(x, y):
        x_root = find(x)
        y_root = find(y)

        if x_root != y_root:
            parent[x_root] = y_root
            for i in range(n): #같지 않은 경우, 모든 자식노드를 갱신하는 작업 수행 필요
                find(i)

    for i in range(n):
        for j in range(n):
            if computers[i][j]:
                union(i, j)

    return len(set(parent))

# 테스트 케이스
# print(solution(3,[[1, 1, 0], [1, 1, 0], [0, 0, 1]]),2)
print(solution(3,[[1, 1, 0], [1, 1, 1], [0, 1, 1]]),1)
# print(solution(1,[[1]]))
# print(solution(3,[[1, 1, 1], [1, 1, 1], [1, 1, 1]]))
# print(solution(4,[[1,1,0,0],[1,1,0,1],[0,0,1,1],[0,1,1,1]]))
print(solution(6,[[1, 0, 1, 1, 0, 0], [0, 1, 0, 0, 1, 1], [1, 0, 1, 1, 1, 1], [1, 0, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1]]))

# 9번 테스트케이스 반례
print(solution(5, [[1, 0, 0, 0, 0], [0, 1, 0, 0, 1], [0, 0, 1, 0, 1], [0, 0, 0, 1, 1], [1, 0, 0, 0, 1]]),2)