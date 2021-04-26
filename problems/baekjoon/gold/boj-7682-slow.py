"""
제목 : 틱택토

아이디어 :
(1) 구현
- 어차피 전체 경우의 수9!해봐야 36만개다
    - 그냥 구현해서 저장한 다음에 그 중에 있는지 비교하면 되잖아
- 재귀로 구현하고, 게임이 끝났으면 백트래킹한다
    - 게임이 끝났다란, 가로 혹은 세로 혹은 대각선으로 연속 3개 존재

- a. 순서의 선택
    - 그냥 1부터 9까지를 permutation 하면 된다
- b. 게임 종료의 체크
    - 가로줄 모두 같은지
    - 세로줄 모두 같은지
    - 대각선 모두 같은지

결과 : 시간초과!
"""
from itertools import permutations
def make_boardstr(board):
    answer = []
    for i in range(len(board)):
        for j in range(len(board)):
            answer.append(board[i][j])
    return ''.join(answer)


def check_endgame(board,shape):
    answer = [shape, shape, shape]
    for i in range(len(board)):
        if board[i] == answer:
            return True
        if [board[j][i] for j in range(len(board))] == answer:
            return True

    if ([board[i][i] for i in range(len(board))] == answer
        or [board[2-i][i] for i in range(len(board))] == answer):
        return True

    return False


def solution():
    BASE_ORDER = "012345678"
    total_order = list(permutations(BASE_ORDER))
    # print(len(total_order))
    # print(total_order)
    available_order = []

    for order in total_order:
        board = [["."]*3 for _ in range(3)]

        for i, turn in enumerate(order):
            if i%2: shape = 'O'
            else: shape = 'X'
            row,col = int(turn)//len(board), int(turn)%len(board)
            board[row][col] = shape

            # print(board,check_endgame(board,shape))
            if check_endgame(board, shape):
                available_order.append(make_boardstr(board))
                break
        if '.' not in board:
            available_order.append(make_boardstr(board))
    # print(available_order)
    # 메인 루프
    while True:
        tc = input()
        if tc == "end": break

        if tc in available_order:
            print("valid")
        else:
            print("invalid")


solution()

# 테스트 케이스
print(solution())
