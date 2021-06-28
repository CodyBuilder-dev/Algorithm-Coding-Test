"""
제목 : [1차] 프렌즈4블록

아이디어 : 단순 for문으로 시간 줄이기
-
"""
def solution(m, n, board):
    def rotate(board, dir):
        new_board = [[None] * m for _ in range(n)]
        if dir == "left":
            pass
        if dir == "right":
            for y in range(m):
                for x in range(n):
                    new_board[x][m - y - 1] = board[y][x]

        return new_board

    board = rotate(board, "right")
    # print("최초의 board",board)


    while True:
        is_quit = True
        checked = []
        for y in range(n-1):
            for x in range(m-1):
                if (board[y][x] and
                    board[y][x] == board[y + 1][x + 1] and
                    board[y][x] == board[y + 1][x] and
                    board[y][x] == board[y][x + 1]):
                    is_quit = False
                    checked.extend([[y,x],[y+1,x],[y,x+1],[y+1,x+1]])

        for c in checked:
            board[c[0]][c[1]] = None

        # print("이번에 지워진 보드 결과는",board)
        if is_quit: break
        board = [list(filter(lambda x: x != None, row)) for row in board]
        board = [x + [None] * (m - len(x)) for x in board]
        # print("중력 적용 후 보드 결과는",board)

    count = 0
    for i in board:
        for j in i:
            if not j: count += 1
    return count

print(solution(4,	5,	["CCBDE", "AAADE", "AAABF", "CCBBF"]))
print(solution(6,	6,	["TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"]))