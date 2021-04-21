"""
제목 : 경주로 건설

아이디어 : DFS
(1) 꼬리재귀 방식으로 구현
- input : 현재좌표, 현재까지의 총 가격
- 탈출조건 :
    - N-1,N-1도달시 -> 전역변수에 값 저장
    - 벽 또는 경계선 도달시 -> 그냥 탈출
- 수행 : 좌우 4칸에 대해 경로 찾기 수행
    - visited는 어떻게 구분할 것인가? -> 꼬리재귀이므로, 들어갈떄 True했다가 나올때 False하면 되지 않을까??

구현 : 실제로 하면 시간초과가 남
-> 백트래킹을 통해 최소값을 뛰어넘으면 탐색하지 말아야 함
-> 그래도 시간초과
"""
from math import inf

def solution(board):
    l = len(board)
    visited = [[False]*l for _ in range(l)]

    minima = inf
    def dfs(board,y,x,direct,cost,visited):
        nonlocal minima
        if (y,x) == (l-1,l-1):
            if cost < minima:
                minima = cost
            return

        for i,next in enumerate([[0,1],[-1,0],[0,-1],[1,0]]):
            new_y,new_x = y + next[0], x + next[1]
            if (new_x < l and new_x >= 0 and new_y < l and new_y >= 0
                and not visited[new_y][new_x]
                and not board[new_y][new_x]):
                visited[new_y][new_x] = True
                new_cost = cost+600 if (i + 1)%4 == direct or (i-1)%4 == direct else cost +100
                if new_cost < minima:
                    dfs(board,new_y,new_x,i,new_cost,visited)
                visited[new_y][new_x] = False

    visited[0][0] = True
    dfs(board,0,0,0,0,visited)
    dfs(board, 0, 0, 1, 0, visited)

    return minima

print(solution([[0,0,0],[0,0,0],[0,0,0]]))
print(solution([[0,0,0,0,0,0,0,1],[0,0,0,0,0,0,0,0],[0,0,0,0,0,1,0,0],[0,0,0,0,1,0,0,0],[0,0,0,1,0,0,0,1],[0,0,1,0,0,0,1,0],[0,1,0,0,0,1,0,0],[1,0,0,0,0,0,0,0]]))

print(solution([[0,0,1,0],[0,0,0,0],[0,1,0,1],[1,0,0,0]]))
print(solution([[0,0,0,0,0,0],[0,1,1,1,1,0],[0,0,1,0,0,0],[1,0,0,1,0,1],[0,1,0,0,0,1],[0,0,0,0,0,0]]))