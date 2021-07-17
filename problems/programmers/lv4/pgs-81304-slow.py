"""
제목 : 미로 탈출

아이디어 : 각 함정별 밟은 수를 기록
- 특정 점에서 출발한다
    - 현재 위치가 함정이면, 밟은 수를 +1한후 판정한다
        - 짝수면, 그대로 간다
        - 홀수면, 현재 함정의 원래 간선에서 뒤집어서 판단한다
    - 현재 위치가 함정이 아니면 그냥 

결과 : 시간초과
"""
from math import inf
from itertools import combinations
from copy import deepcopy
from queue import PriorityQueue

def swap_board(board, trap_str):
    new_board = deepcopy(board)

    for i,v in enumerate(trap_str):
        if v == "1":
            for j in range(len(board)):
                new_board[i][j], new_board[j][i] = new_board[j][i], new_board[i][j]

    return new_board

def solution(n, start, end, roads, traps):
    # 보드 파싱
    board = [[inf] * n for _ in range(n)]
    for road in roads:
        s, e, c = road
        if c < board[s - 1][e - 1]:
            board[s - 1][e - 1] = c
    # return board

    # 모든 함정의 경우의 수 2^len(traps)에 대한 cost dict 생성
    # 함정 문자열은, 모든 노드 중 밟은 함정노드가 1로 되어있는 문자열
    # 이후 함정 dict를 통해 특정노드가 함정인지 아닌지 쉽게 파악가능
    # 모든 함정 경우에 대해 보드도 미리 만들어 둔다
    cost = {}
    boards = {}

    for i in range(len(traps)+1):
        selected_traps = combinations(traps, i)

        for trap in selected_traps:
            active_traps = 0
            for node in trap:
                active_traps += 2**(node-1)
                # active_traps[node-1] = "1"

            cost[active_traps] = [inf]*n
            boards[active_traps] = swap_board(board, bin(active_traps)[2:][::-1])

    cost[0][start-1] = 0
    traps = dict.fromkeys(list(map(lambda x:x-1,traps)))
    # return traps
    # return cost
    # return boards

    # 함정상태 문자열을 가진 채로 다익스트라 고고
    pq = PriorityQueue()
    pq._put((cost[0][start-1], start-1, 0))


    while not pq.empty():
        current_cost, current_node, current_trap_int = pq._get()
        if current_node == end-1:
            return current_cost

        current_board = boards[current_trap_int]

        for idx, v in enumerate(current_board[current_node]):
            if v != inf:
                next_trap_int = current_trap_int
                if idx in traps:
                    next_trap_int = current_trap_int ^ (1 << idx)

                if (cost[current_trap_int][idx] >
                    current_cost + current_board[current_node][idx]):
                    cost[current_trap_int][idx] = current_cost + current_board[current_node][idx]
                    pq._put((cost[current_trap_int][idx], idx, next_trap_int))
    return min(list(map(lambda x:x[end-1], cost.values())))



print(solution(3,	1,	3,	[[1, 2, 2], [3, 2, 3]],[2]))
print(solution(4,	1,	4,	[[1, 2, 1], [3, 2, 1], [2, 4, 1]],[2, 3]))