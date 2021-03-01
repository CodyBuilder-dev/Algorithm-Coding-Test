"""
일단 삼각형 구현은 가능
n, n-1, n-2, n-3 ... 1
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