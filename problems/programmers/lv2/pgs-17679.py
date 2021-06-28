"""
제목 : [1차] 프렌즈4블록

아이디어 : 완전탐색과 BFS를 섞은 알고리즘을 2차원 배열이지만 스택처럼 동작하는 자료구조에 버무려라
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
    def bfs_right(y, x):
        if not board[y][x]: return

        frnd = board[y][x]

        q = []
        q.append([y, x])
        visited = [[False] * m for _ in range(n)]
        checked = []
        while q:
            y, x = q.pop(0)
            if y + 1 < n and x + 1 < m:
                if (frnd == board[y + 1][x + 1] and
                        frnd == board[y + 1][x] and
                        frnd == board[y][x + 1]):
                    temp = [[y, x], [y + 1, x], [y, x + 1], [y + 1, x + 1]]
                    temp = [t for t in temp if not visited[t[0]][t[1]]]
                    for t in temp:
                        visited[t[0]][t[1]] = True
                    checked.extend(temp)
                    q.extend(temp)

            if y + 1 < n and x - 1 >= 0:
                if (frnd == board[y + 1][x - 1] and
                        frnd == board[y + 1][x] and
                        frnd == board[y][x - 1]):
                    temp = [[y, x], [y + 1, x], [y, x - 1], [y + 1, x - 1]]
                    temp = [t for t in temp if not visited[t[0]][t[1]]]
                    for t in temp:
                        visited[t[0]][t[1]] = True
                    checked.extend(temp)
                    q.extend(temp)

        return checked

    while True:
        is_available = False
        for y in range(n):
            for x in range(m):
                checked = bfs_right(y, x) or []
                # print("선택된 점들은",checked)
                for c in checked:
                    board[c[0]][c[1]] = None
                    is_available = True
                # print("이번에 지워진 보드 결과는",board)
        if not is_available: break
        board = [list(filter(lambda x: x != None, row)) for row in board]
        board = [x + [None] * (m - len(x)) for x in board]
        # print(board)

    count = 0
    for i in board:
        for j in i:
            if not j: count += 1
    return count