"""
제목 : 네트워크

아이디어 : 유니온 파인드
- 부모 배열을 이용한 유니온 파인드
예외처리 :
"""

def solution(n, computers):
    parent = [x for x in range(n)]

    def find(x):
        if parent[x] == x:
            return x

        parent[x] = find(parent[x])
        return parent[x]

    def union(x, y):
        x = find(x)
        y = find(y)
        if x < y : parent[y] = x
        else : parent[x] = y

    for node in range(n) :
        for i,connected in enumerate(computers[node]):
            if node == i : continue
            if connected == 1 :
                union(node,i)

    return len(set(parent))

# 테스트 케이스
print(solution(3,[[1, 1, 0], [1, 1, 0], [0, 0, 1]]))
print(solution(3,[[1, 1, 0], [1, 1, 1], [0, 1, 1]]))
print(solution(1,[[1]]))
print(solution(3,[[1, 1, 1], [1, 1, 1], [1, 1, 1]]))
print(solution(4,[[1,1,0,0],[1,1,0,1],[0,0,1,1],[0,1,1,1]]))
n = 6
computers = [[1, 0, 1, 1, 0, 0], [0, 1, 0, 0, 1, 1], [1, 0, 1, 1, 1, 1], [1, 0, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1]]
print(solution(n,computers))
