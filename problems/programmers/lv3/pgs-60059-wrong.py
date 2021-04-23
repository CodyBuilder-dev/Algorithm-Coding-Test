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
                luY , luX = max(i,m-1) ,max(j,m-1)
                rlY , rlX = min(i+m-1,n+m-1),min(j+m-1,n+m-1)

                # key 좌상단 / 우하단
                newKey = turn(key,k)
                isOpen = True
                for ii in range(luY,rlY) :
                    for jj in range(luX,rlX) :
                        if newKey[m-(rlY-luY)+ii-luY][m-(rlX-luX)+jj-luX] ^ board[ii][jj] == 1:
                            continue
                        else :
                            isOpen = False
                            break
    return isOpen