"""
제목 : 자물쇠와 열쇠

카테고리

아이디어 : 경우의수 탐색은 완탐, 확인은 비트마스크
1. for 문 돌리면서 회전시킨다
-> 행렬 회전 알고리즘은, 
행 -> 2-열
열 -> 행

2. 겹쳐본다음, 겹치는 부분을 판정한다
-> 좌상단 꼭지점, 우하단 꼭지점의 좌표만 얻으면 ㄱㄴ
-> 비교 판정은 XOR
"""

def turn(key,num) :
    newKey =key
    for i in range(num) :
        newKey = turn90(newKey)
    return newKey

def turn90(key) :
    n = len(key)
    newKey = [[0]*n for i in range(n)]
    for i in range(n) :
        for j in range(n) :
            newKey[j][2-i] = key[i][j]         
    return newKey

def solution(key, lock) :
    n = len(lock)
    m = len(key)
    board= [[0] *(n+2*m-2) for i in range(n+2*m-2)]

    for i in range(m-1,m+n-1) :
        for j in range(m-1,m+n-1) :
            board[i][j] = lock[i-m+1][j-m+1]

    for i in range(n+m) :
        for j in range(n+m) :
            for k in range(3) :
                # board 좌상단 / 우하단
                luY , luX = max(i,m) ,max(j,m)
                rlY , rlX = min(i+m,n+m),min(j+m,n+m)

                # key 좌상단 / 우하단

                isOpen = True
                for ii in range(luY,rlY) :
                    for jj in range(luX,rlX) :
                        if key[m-(rlY-luY)][m-(rlX-luX)] ^ board[ii][jj] :
                            continue
                        else :
                            isOpen = False
                            break
    return isOpen

key = [[0, 0, 0], [1, 0, 0], [0, 1, 1]]
lock = 	[[1, 1, 1], [1, 1, 0], [1, 0, 1]]
print(solution(key,lock))
print(1 ^ 1)