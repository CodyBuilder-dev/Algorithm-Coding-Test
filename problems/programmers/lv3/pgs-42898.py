"""
제목 : 등굣길

아이디어 : 일반적인 DP
- 맵을 만든다
- dp를 한다
"""


def solution(m, n, puddles):
    board = [[0] * m for i in range(n)]
    for coord in puddles:
        board[coord[1] - 1][coord[0] - 1] = -1

    board[0][0] = 1
    for i in range(n):
        for j in range(m):
            if board[i][j] == -1:
                continue
            if i == 0 and j == 0:
                continue
            if i == 0:
                board[i][j] = board[i][j - 1]
                continue
            if j == 0:
                board[i][j] = board[i - 1][j]
                continue
            board[i][j] += board[i - 1][j] if board[i - 1][j] != -1 else 0
            board[i][j] += board[i][j - 1] if board[i][j - 1] != -1 else 0

    # 파이썬이 아닌 경우에는, 최종 결과가 아니라 매 연산마다 모듈러 연산을 수행해야 함
    # 파이썬은 정수의 크기 제한이 훨씬 크므로 결과에만 수행해도 가능
    return board[n - 1][m - 1] %1000000007
print(solution(4,3,[[2, 2]]))