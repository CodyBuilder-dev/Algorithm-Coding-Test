def solution(n, computers):
    parent = [x for x in range(n)]

    def find(x):
        if parent[x] == x:
            return x
				# x -> y ->r로 진행된다고 하면 x,y의 부모가 모두 r로 갱신된다
        parent[x] = find(parent[x])
        return parent[x]

    def union(x, y):
        x = find(x)
        y = find(y)

        if x < y:
            parent[y] = x
        elif y < x:
            parent[x] = y

    answer = n
    for i in range(n):
        for j in range(i+1,n):
            if computers[i][j] and find(i) != find(j):
                union(i,j)
                answer -= 1
		# return len(set(parent)) # 이처럼 게산하면 틀리게 된다
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