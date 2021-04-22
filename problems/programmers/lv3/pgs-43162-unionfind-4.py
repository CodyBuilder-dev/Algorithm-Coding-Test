def solution(n, computers):
    answer = 0

    parent = [-1] * n

    def find(u):
        if parent[u] < 0:
            return u
        else:
            parent[u] = find(parent[u])
            return parent[u]

    def merge(u, v):
        u = find(u)
        v = find(v)

        if u == v:
            return False

        parent[u] += parent[v]
        parent[v] = u
        return True

    for i in range(n):
        for j in range(i + 1, n):
            if computers[i][j] == 1:
                merge(i, j)

    print(parent)
    visited = [False] * n
    for i in range(n):
        u = find(i)
        if not visited[u]:
            answer += 1
            visited[u] = True

    return answer

# 테스트 케이스
# print(solution(3,[[1, 1, 0], [1, 1, 0], [0, 0, 1]]),2)
print(solution(3,[[1, 1, 0], [1, 1, 1], [0, 1, 1]]),1)
# print(solution(1,[[1]]))
# print(solution(3,[[1, 1, 1], [1, 1, 1], [1, 1, 1]]))
# print(solution(4,[[1,1,0,0],[1,1,0,1],[0,0,1,1],[0,1,1,1]]))

print(solution(6,[[1, 0, 1, 1, 0, 0], [0, 1, 0, 0, 1, 1], [1, 0, 1, 1, 1, 1], [1, 0, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1]]))

# 9번 테스트케이스 반례
print(solution(5, [[1, 0, 0, 0, 0], [0, 1, 0, 0, 1], [0, 0, 1, 0, 1], [0, 0, 0, 1, 1], [1, 0, 0, 0, 1]]),2)