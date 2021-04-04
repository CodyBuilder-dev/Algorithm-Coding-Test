"""
제목 : 블록 이동하기

아이디어 : 완전 탐색 + 이동 구현이 복잡
- 기본적으로 가능한 이동 방식 : 4+2+2
- 다음칸으로 갈지말지 결정하는 로직
    - 다음 칸이 둘다 visited면 안 가도 됨
- 다음칸으로 움직임 가능할지 결정하는 로직
    - 회전은 경로 2개중 하나라도 1이 막혀있으면 불가능
    - 이동도 경로 1개에 1이 막혀있으면 불가능
- 회전은 어떻게 정의도는가
    - (a,b)(c,d)라면
    -


구현 : bfs
- 회전가능 여부, 이동가능 여부를 검사하면서 queue에 넣기
- bfs
    - 큐에서 뽑기
    - 다음 가능한 칸들 큐에 넣기
    - 큐에 넣은 칸 visited

- 근데 회전가능 여부를 어떻게 체크하지
    - 회전체크(축좌표, 다음 경로)
        - True/False 반환

- 이동가능 여부
    - 이동체크(방향)
        -True/False 반환

"""
from collections import deque

def elem_sum(tup1,tup2):
    new = []
    for i,j in zip(tup1,tup2):
        new.append(i+j)
    return tuple(new)

def check_ud(board, visited, nexts):
    if (board[nexts[0][0]][nexts[0][1]] == 1 or board[nexts[1][0]][nexts[1][1]] == 1) \
        or (visited[nexts[0][0]][nexts[0][1]] == 1 and visited[nexts[1][0]][nexts[1][1]] == 1):
        return False
    return True


def check_lr(board, visited, next):
    if board[next[0]][next[1]] == 1 \
        or visited[next[0]][next[1]] == 1 :
        return False
    return True

def check_rotate(board,visitied,wing, next):
    if (board[next[0][0]][next[0][1]] == 1 or board[next[1][0]][next[1][1]] == 1) \
        or (visited[next[0][0]][next[0][1]] == 1 and visited[next[1][0]][next[1][1]] == 1):
        return False
    return True

def find_path(board):
    start = [(0,0),(0,1)] #tail, head
    n = len(board) - 1
    end = (n,n)

    dq = deque()
    dq.append(start)

    count = 0
    visited = [[False]*n for i in range(n)]

    #출발지
    visited[start[0][0]][start[0][1]] = True
    visited[start[0][0]][start[0][1]] = True
    while len(dq)>0 :
        current = dq.popleft()
        # 회전 체크
        for pivot in current:
            for i in [-1,1]:
                for j in [-1,1]:
                if check_rotate(pivot, (pivot)


        # 이동 체크








def solution(board):
    answer = find_path(board)
    return answer