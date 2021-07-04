"""
제목 : 크레인 인형뽑기 게임

요구사항 : 
1. 그냥 크레인을 구현만 하면 된다
2. 구현해서 순서대로 잘 따라만 가면 됨

구현과정
1. 2차원 배열 만들기
2. pop(n) 함수를 구현해 n번째에서 뽑아내기
3. push 함수를 구현해, 바구니에 밀어넣고, 2개 연속이면 터뜨리기
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

if __name__ == "__main__" :
    board = [[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]]	
    moves = [1,5,3,5,1,2,1,4]
    # print(makeStack(board))
    solution(board,moves)