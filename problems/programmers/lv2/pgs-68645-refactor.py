"""
제목 : 삼각 달팽이
"""


def solution(n):
    dx = [0, 1, -1]; dy = [1, 0, -1]
    b = [[0] * i for i in range(1, n + 1)]
    x, y, num, d = 0, 0, 1, 0

    while num <= (n + 1) * n // 2:
        b[y][x] = num
        ny = y + dy[d]
        nx = x + dx[d]
        num += 1
        if 0 <= ny < n and 0 <= nx <= ny and b[ny][nx] == 0:
            y, x = ny, nx
        else:
            d = (d + 1) % 3;
            y += dy[d]
            x += dx[d]

    return sum(b,[])


print(solution(6))
