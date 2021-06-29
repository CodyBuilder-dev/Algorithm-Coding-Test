"""
제목 : 게임 맵 최단거리

아이디어 : 최단거리이므로 BFS
(1) 최단거리 저장 매커니즘
- 별도의 COST 배열에 현재지점까지의 최단거리를 저장하거나
- 혹은 BFS를 돌면서, COST를 큐에 같이 넣어서 전달한다

(2) 도달가능 불가능 판별 로직
- COST배열은 초기에 inf로 초기화한다
- 만약 도달하지 못했다면, inf로 그대로 있을 것이므로 그러면 -1을 ㅂ반환한다.
"""
def solution(maps):
    n = len(maps)
    m = len(maps[0])
    visited = [[False]*m for _ in range(n)]

    q = []
    q.append([0,0,1])
    visited[0][0] = True
    while q:
        y, x, distance = q.pop(0)

        for i in [[0,1],[-1,0],[0,-1],[1,0]]:
            next_y, next_x = y+i[0],x+i[1]
            if next_y < n and next_y >= 0 and next_x < m and next_x >= 0:
                if maps[next_y][next_x] == 1:
                    if next_y == n - 1 and next_x == m - 1:
                        return distance + 1
                    if not visited[next_y][next_x]:
                        visited[next_y][next_x] = True
                        q.append([next_y,next_x, distance +1])

    return -1

# 테스트 케이스
# print(solution([[1,0,1,1,1],[1,0,1,0,1],[1,0,1,1,1],[1,1,1,0,1],[0,0,0,0,1]]))
print(solution([[1,0,1,1,1],[1,0,1,0,1],[1,0,1,1,1],[1,1,1,0,0],[0,0,0,0,0]]))
