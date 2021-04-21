"""
제목 : 경주로 건설

아이디어 : BFS
- 연결된 모든 다음 칸을 검토한다
- 다음칸으로 갔을 경우 비용을 계산한다
    - 비용이 더 작을 경우, 기존 방문여부 관계없이 비용과 방향을 저장한다
    - 비용이 더 큰 경우 그냥 넘긴다
- 도착점에 도달할 때 까지 반복한다

"""
from math import inf
from collections import deque

def solution(board):
    l = len(board)

    cost = [[[inf]*l for _ in range(l)] for __ in range(4)]
    for i in range(4):
        cost[i][0][0] = 0

    dq = deque([[0,0,0],[0,0,3]])

    while dq:
        y,x,direct = dq.popleft()
        # 주석처리 해도 되고 안해도 된다. 왜일까?
        if (y,x) == (l-1,l-1):
            continue

        for i,next in enumerate([[0,1],[-1,0],[0,-1],[1,0]]):
            new_y,new_x = y + next[0], x + next[1]
            if (new_x < l and new_x >= 0 and new_y < l and new_y >= 0
                and not board[new_y][new_x]):

                new_cost = cost[direct][y][x]+600 if (i + 1)%4 == direct or (i-1)%4 == direct else cost[direct][y][x] +100
                # 반드시 <로 해줘야 하고, <=로 하면 시간초과가 난다. 왜일까?
                if new_cost < cost[i][new_y][new_x]:
                    cost[i][new_y][new_x] = new_cost
                    dq.append([new_y,new_x,i])

    return min(map(lambda x:x[l-1][l-1], cost))

print(solution([[0,0,0],[0,0,0],[0,0,0]]))
print(solution([[0,0,0,0,0,0,0,1],[0,0,0,0,0,0,0,0],[0,0,0,0,0,1,0,0],[0,0,0,0,1,0,0,0],[0,0,0,1,0,0,0,1],[0,0,1,0,0,0,1,0],[0,1,0,0,0,1,0,0],[1,0,0,0,0,0,0,0]]))

print(solution([[0,0,1,0],[0,0,0,0],[0,1,0,1],[1,0,0,0]]))
print(solution([[0,0,0,0,0,0],[0,1,1,1,1,0],[0,0,1,0,0,0],[1,0,0,1,0,1],[0,1,0,0,0,1],[0,0,0,0,0,0]]))

print(solution( [[0, 0, 0, 0, 0],
        [0, 1, 1, 1, 0],
        [0, 0, 1, 0, 0],
        [1, 0, 0, 0, 1],
        [0, 1, 1, 0, 0]]))