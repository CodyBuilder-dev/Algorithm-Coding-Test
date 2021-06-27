"""
제목 : 삼각 달팽이

아이디어 : 단순 구현
- 규칙에 따라 채워넣는 동작을 구현합니다
    - 아래로 내려가기 -> 오른족으로 움직이기 -> 좌측 대각선 위로 올라가기
    - 매 이동마다 이동거리가 1씩 짧아짐을 구현


"""

def draw(arr,n) :
    row,col,num = 0,0,1
    
    while n > 0 :
        for i in range(row,row+n) :
            arr[i][col] = num
            num += 1
        
        row,col,n = i,col+1,n-1
        
        if n <= 0 : break

        for j in range(col,col+n) :
            arr[row][j] = num
            num += 1

        row,col,n = row-1,j-1,n-1
        
        if n <= 0 : break

        for k,l in zip(range(row,row-n,-1),range(col,col-n,-1)) :
            arr[k][l] = num
            num += 1

        row,col,n = k+1,l,n-1
        
        if n <= 0 : break
    
    return arr


def solution(n):
    answer = [[0]*n for i in range(n)]
    answer = draw(answer,n)
    
    a = []
    for i in range(n) :
        for j in range(n) :
            if answer[i][j] != 0:
                a.append(answer[i][j])
                 
    return a

n = 6
print(solution(n))