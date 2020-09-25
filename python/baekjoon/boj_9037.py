"""
접근 방법 : 구현
1. 홀수 검사 및 보충
2. 다음 아이
3. 무한반복

"""
from collections import deque
# deque의 문제점 : elementwise 연산 불가

def checkSame(lst) :
    if min(lst) == max(lst) : return True
    else : return False

def checkOdd(n) :
    if n % 2 == 1 : return True
    else : return False

T = int(input())
for tc in range(T) :
    N = int(input())
    C = list(map(int,input().split()))
    q = deque(C)

    # 처음 보충
    # for i in range(N) :
    #     if checkOdd(q[i]) : q[i] +=1
    for i in range(N) :
        if checkOdd(C[i]) : C[i] +=1
    
    cirNum = 0 
    while True : 
        if checkSame(C) : break
        cirNum+=1
        # halfQ = deque(map(lambda x:x//2,q))
        # tempQ = q.copy()
        # tempQ.appendleft(tempQ.pop())
        # tempQ = deque(map(lambda x:x//2,tempQ))
        # q = q-halfQ+tempQ
        tempC = [C.pop()] + C
        tempC = list(map(lambda x:x//2,tempC))
        halfC = list(map(lambda x:x//2,C))
        C = C 
        for i in range(N) :
            if checkOdd(q[i]) : q[i] +=1
    
        print(halfQ)
                
        
    print(cirNum)  
        


    
