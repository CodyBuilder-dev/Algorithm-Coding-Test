"""
제목 : 틱택토

아이디어 :
(1)valid한 게임판의 개수 조건?
    - 게임이 끝까지 간 경우 (.가 없음)
        - X는 5개 O는 4개
    - 게임이 중간에 끝난 경우(.가 있음)
        - X가 이겼으면 반드시 홀수, X== O+1
        - O가 이겼으면 반드시 짝수, X== O

        - 그리고 반드시 check_endgame했을때 True여야 함
"""
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
    # 메인 루프
    while True:
        tc = input()
        if tc == "end": break

        tc = list(tc)
        x_count = tc.count('X')
        o_count = tc.count('O')
        board = [tc[:3],tc[3:6],tc[6:]]

        if '.' in tc:
            if check_endgame(board,'X') and not check_endgame(board,'O')\
                and x_count == o_count + 1:
                print("valid")
            elif check_endgame(board,'O') and not check_endgame(board,'X')\
                and x_count == o_count:
                print("valid")
            else:
                print("invalid")
        elif not check_endgame(board,'O')\
            and x_count == o_count + 1:
            print("valid")
        else:
            print("invalid")

# 제출용
solution()