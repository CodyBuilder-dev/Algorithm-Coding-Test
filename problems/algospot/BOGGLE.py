"""
지저분하게 푼 코드

"""
def solV1(board, y, x, strToFind,strFound):
    # 탈출 조건
    if y < 0 or y >= 5 or x < 0 or x >= 5:
        return
    # 1. 첫글자부터 안 맞는 경우
    if board[y][x] != strToFind[0]:
        return
    # 2. 다 찾은 경우
    if board[y][x] == strToFind[0] and len(strToFind) == 1:
        global word_list
        word_list[strFound+board[y][x]] = True
        return

    # 현재칸을 -1로 칠한 후 다음 재귀로 넘김
    if (board[y][x] == strToFind[0]):
        for dy in [-1,0,1] :
            for dx in [-1,0,1] :
                if dy == 0 and dx == 0 : continue
                solV1(board,y+dy,x+dx,strToFind[1:],strFound+board[y][x])

def boggle() :
    c = int(input())
    for tc in range(c):
        global board
        board = []
        for row in range(5):
            board.append(list(input()))
        # print(board)

        words = []
        n = int(input())
        for i in range(n):
            words.append(input())
        print(words)

        global word_list
        word_list = dict.fromkeys(words)
        for i in range(5):
            for j in range(5):
                for word in words:
                    if word_list[word] != True :
                        # solV1(board, i, j, word, "")
                        word_list[word] = solV2(i,j,word)

    for key,values in word_list.items():
        if values == True : print(key+ " YES")
        else : print(key+" NO")

"""
깔끔하게 정리한 코드
"""
def solV2(y, x, strToFind):
    # 탈출 조건
    if y < 0 or y >= 5 or x < 0 or x >= 5:
        return False
    # 1. 첫글자부터 안 맞는 경우
    if board[y][x] != strToFind[0]:
        return False
    # 2. 다 찾은 경우
    if len(strToFind) == 1:
        return True

    # 현재칸을 -1로 칠한 후 다음 재귀로 넘김
    for dy in [-1,0,1] :
        for dx in [-1,0,1] :
            if dy == 0 and dx == 0 : continue
            if(solV2(y+dy,x+dx,strToFind[1])):
                return True
    return False


boggle()