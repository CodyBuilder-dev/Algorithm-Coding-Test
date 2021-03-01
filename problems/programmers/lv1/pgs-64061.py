"""
제목 : 크레온 인형뽑기 게임
"""

def makeStack(board) :
    n = len(board)
    stack = [[] for _ in range(n)]
    for i in range(n-1,-1,-1) :
        for j in range(n) :
            if(board[i][j] != 0) : stack[j].append(board[i][j])
    return stack

def popDoll(stack, basket, n, cnt) :
    if len(stack[n-1]) == 0 :
        return stack,basket,cnt
    value = stack[n-1].pop()
    # print(value)
    if len(basket) != 0 and basket[-1] == value :
        basket.pop()
        cnt += 2
    else :
        basket.append(value)
    # print(stack)
    # print(basket)
    # print("카운트 : ",cnt)
    return stack,basket,cnt
    
def solution(board, moves) :
    stack = makeStack(board)
    basket =[]
    cnt = 0
    for move in moves :
        stack,basket,cnt = popDoll(stack,basket,move,cnt)
    return cnt