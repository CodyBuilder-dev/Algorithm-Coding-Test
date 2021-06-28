"""
제목 : 행렬 테두리 회전하기

아이디어 : 구현을 할수밖에 없는 듯
- 회전을 2차원 상태에서 하기는 힘들다
- 테두리의 원소들을 시계방향으로 추출해 1차원에서 회전한다
    - 시작점부터 오른쪽으로 추출
    - 오른쪽에서 아래로 추출
    - 아래에서 왼쪽으로 가로로 추출
    - 왼쪽에서 위로 추출
- 회전이 완료되면 순서대로 다시 집어넣는다
    - 위와 동일하게 수행
"""


def extract_board(board, y1, x1, y2, x2):
    answer = []
    answer.extend(board[y1][x1:x2+1])
    for i in range(y1+1,y2+1):
        answer.append(board[i][x2])
    for i in range(x2-1,x1-1,-1):
        answer.append(board[y2][i])
    for i in range(y2-1,y1,-1):
        answer.append(board[i][x1])

    return answer

def rotate(arr):
    return arr[-1:] + arr[:-1]

def insert_board(board, arr, y1, x1, y2, x2):
    pointer = 0
    for i in range(x1,x2+1):
        board[y1][i] = arr[pointer]
        pointer += 1
    for i in range(y1+1,y2+1):
        board[i][x2] = arr[pointer]
        pointer += 1
    for i in range(x2-1,x1-1,-1):
        board[y2][i] = arr[pointer]
        pointer += 1
    for i in range(y2-1,y1,-1):
        board[i][x1] = arr[pointer]
        pointer += 1



def solution(rows, columns, queries):
    board = [[0] * columns for _ in range(rows)]

    for i in range(rows):
        for j in range(columns):
            board[i][j] = i*columns + j + 1
    answer = []
    for q in queries:
        y1, x1, y2, x2 = q
        result = rotate(extract_board(board, y1-1, x1-1, y2-1, x2-1))
        insert_board(board,result, y1-1,x1-1,y2-1,x2-1)
        answer.append(min(result))
        # print(extract_board(board, y1-1 ,x1 -1, y2 -1, x2-1))
    return answer
# 테스트케이스
print(solution(6,	6,	[[2,2,5,4],[3,3,6,6],[5,1,6,3]]))
print(solution(3,	3,	[[1,1,2,2],[1,2,2,3],[2,1,3,2],[2,2,3,3]]))
print(solution(100,	97,	[[1,1,100,97]]))


