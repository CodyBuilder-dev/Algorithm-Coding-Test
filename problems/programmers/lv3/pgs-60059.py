"""
아이디어 : 구현과 시뮬레이션
(1) 회전 구현
- 90도 회전을 구현한다
- 1,2,3회에 따라 돌린다

(2) 이동 구현
- key와 map을 합친 사각형을 가정한다
    - key가 M, map N이면
    - N+2(M-1)
    - map이 위치한 부분은 M-1,M-1부터 M+N-1,M+N-1

- key의 좌상단 움직인다
    - 좌상단이 결정되면 우하단의 좌표를 구할 수 있다

(3) 비교 구현
- 지도가 존재하는 부분에 XOR을 수행했을 때 모든 곳이 1
    - key가 있는 곳은 key,
    - key가 없는 곳은 0
"""
import copy

def rotate(key, n):
    if n == 0:
        return key

    if n == 1:
        return rotate_90(key)

    return rotate_90(rotate(key, n - 1))


def rotate_90(key):
    new_key = [[None] * len(key) for _ in range(len(key))]

    for y in range(len(key)):
        for x in range(len(key)):
            new_key[x][len(key) - y - 1] = key[y][x]

    return new_key




def solution(key, lock):
    M,N = len(key),len(lock)
    total_size = 2*M+N-2

    # 전체 맵 구성
    total = [[0]*total_size for _ in range(total_size)]
    for i in range(M-1,M+N-1):
        for j in range(M-1,M+N-1):
            total[i][j] = lock[i-(M-1)][j-(M-1)]

    # 이동 구성
    for rot_num in range(4):
        temp_key = rotate(key,rot_num)
        for i in range(M+N-1):
            for j in range(M+N-1):
                temp_total = copy.deepcopy(total)
                for k in range(M):
                    for l in range(M):
                        temp_total[k+i][l+j] = total[k+i][l+j] ^ temp_key[k][l]
                print(temp_total)
                # 합이 N*N이면 True 반환
                sum = 0
                for k in range(M-1,M+N-1):
                    for l in range(M-1,M+N-1):
                        sum += temp_total[k][l]
                if sum == N**2:
                    print(temp_total)
                    return True
    return False

print(solution([[0, 0, 0], [1, 0, 0], [0, 1, 1]],[[1, 1, 1], [1, 1, 0], [1, 0, 1]]))
# print(0^0)