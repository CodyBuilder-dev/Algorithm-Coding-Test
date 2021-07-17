"""
제목 : 미로 탈출

구현 :
- 인접 행렬 대신 dict로 구현
- 간선과 역간선을 미리 적어 놓음
- 모든 함정 경우에 보드를 미릐 그려 둠

"""
from math import inf
from itertools import combinations
from copy import deepcopy
from queue import PriorityQueue


def swap_board(board, trap_str):
    new_board = deepcopy(board)

    for i, v in enumerate(trap_str):
        if v == "1":
            for k in new_board:
                if k == i:
                    for e in new_board[k]:
                        new_board[k][e][1] *= -1
                elif i in new_board[k]:
                    new_board[k][i][1] *= -1

    return new_board


def solution(n, start, end, roads, traps):
    # 보드 생성
    # 역간선을 미리 만들어 둔다
    board = {}
    for road in roads:
        s, e, c = road
        if not s - 1 in board:
            board[s - 1] = {}
        if not e - 1 in board:
            board[e - 1] = {}

        board[s - 1][e - 1] = [c, 1]
        board[e - 1][s - 1] = [c, -1]
    # return board

    # 함정 상태별 최소거리 cost 기록
    # 보드도 미리 만들어 둔다
    cost = {}
    boards = {}
    for i in range(len(traps) + 1):
        selected_traps = combinations(traps, i)

        for trap in selected_traps:
            active_traps = 0
            for node in trap:
                active_traps += 2 ** (node - 1)
                # active_traps[node-1] = "1"

            cost[active_traps] = [inf] * n
            boards[active_traps] = swap_board(board, bin(active_traps)[2:][::-1])
    # return boards

    cost[0][start - 1] = 0
    traps = dict.fromkeys(list(map(lambda x: x - 1, traps)))
    # return traps

    # 함정상태 문자열을 가진 채로 다익스트라 고고
    pq = PriorityQueue()
    pq._put((cost[0][start - 1], start - 1, 0))

    while not pq.empty():
        current_cost, current_node, current_trap_int = pq._get()
        if current_node == end - 1:
            return current_cost

        current_board = boards[current_trap_int]

        for k, v in current_board[current_node].items():
            if v[1] == 1:
                next_trap_int = current_trap_int
                if k in traps:
                    next_trap_int = current_trap_int ^ (1 << k)

                if (cost[current_trap_int][k] >
                        current_cost + current_board[current_node][k][0]):
                    cost[current_trap_int][k] = current_cost + current_board[current_node][k][0]
                    pq._put((cost[current_trap_int][k], k, next_trap_int))

    return min(list(map(lambda x: x[end - 1], cost.values())))


print(solution(3, 1, 3, [[1, 2, 2], [3, 2, 3]], [2]))
print(solution(4, 1, 4, [[1, 2, 1], [3, 2, 1], [2, 4, 1]], [2, 3]))
