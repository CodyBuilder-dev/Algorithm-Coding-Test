"""
제목 : 방문 길이

아이디어 : 방문여부 기록 배열 사용
(1) Hash 구현
- 좌표평면의 길이가 가로세로 10x10이므로 저장할만 하다
    - key : (x,y)
    - value = [LRUD]=[False,False,False,False]
- 각 이동마다 출발지와 LRUD를 기록
    - 이때 왼쪽에서의 R과 오른쪽에서의 L은 같은 길이다
-> 더 어려워 지는것 같다

(2) 4차원 배열로 구현
- 방문한 경로 정보 저장
    - 각 좌표를 +5,+5해서 0,0부터 10,10까지 좌표를 정의
    - visited[출발y][출발x][도착y][도착x] 구현
    
- 최종적으로 1의 총 갯수 센 후 //2
    - 다차원 배열의 합은, 재귀적으로 구할 수 있음
"""
def rec_sum(lst,dim):
    if dim == 1:
        return sum(lst)

    answer = 0
    for sub_lst in lst:
        answer += rec_sum(sub_lst,dim-1)

    return answer

def solution(dirs):
    MAX = 10 + 1
    board = [[[[0]* MAX for _ in range(MAX)] for __ in range(MAX)] for ___ in range(MAX)]

    dir_map = {
        "L":[0,-1],
        "R":[0,1],
        "U":[-1,0],
        "D":[1,0],
    }

    current = [5,5]
    for dir in dirs:
        y,x = current
        # print(current)
        next_y = y + dir_map[dir][0]
        next_x = x + dir_map[dir][1]

        if next_y >= 0 and next_y < MAX and next_x >= 0 and next_x < MAX:
            board[y][x][next_y][next_x] = 1
            board[next_y][next_x][y][x] = 1
            current = [next_y,next_x]

    return rec_sum(board,4)//2

print(solution("ULURRDLLU"))
print(solution("LULLLLLLU"))