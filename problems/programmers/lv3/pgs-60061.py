"""
제목 : 기둥과 보 설치

아이디어 : 구현을 잘 하면 된다
(1) 우선 입출력을 이해
- 입 :[가로좌표,세로좌표, 종류, 설치삭제여부]
- 출 : [가로좌표, 세로좌표, 종류]
    - 정렬해서 반환
(2) 들어와서 행하는 동작을 정의
- 동작을 받는다
    - 설치일 경우
        - 보면,
            - 해당지점 아래 혹은 오른쪽 아래에 기둥이 있거나
            - 해당지점 왼쪽 오른쪽에 모두 보가 있으면 된다
        - 기둥이면,
            - 해당지점이 바닥이거나
            - 해당지점 아래에 기둥이 있거나
            - 해당지점 이나 왼쪽에 보가 있으면 된다
    - 삭제면, 삭제 후 전체를 검사한다
        - 전체검사는 설치조건을 다 검사하며ㅓㄴ 된다


구현 :
- (기둥,보)를 n*n으로 갖는 board를 만든다
- 왼쪽 아래부터 0,0임에 주의한다

"""
def make_gidoong(board,x,y):
    if y == 0:
        return True
    if board[5 - y + 1][x][0]:
        return True
    if x >= 1 and board[5 - y][x-1][1]:
        return True
    # 빼먹은 조건: 해당지점 바로 아래에 보가 있을 때
    if x < len(board) and board[5-y][x][1]:
        return True
    else: return False

def make_bo(board,x,y):
    if (board[5 - y + 1][x][0] or board[5 - y + 1][x + 1][0]) \
        or (x>= 1  and board[5 - y][x-1][1] and board[5 - y][x + 1][1]):
        return True
    else: return False

def check_delete(board,x,y,type): # 해당 기둥이나 보의 존재가능여부 검사
    if type == 0: # 기둥
        return make_gidoong(board,x,y)
    else: # 보
        return make_bo(board,x,y)

def solution(n, build_frame):
    board = [[[0,0] for j in range(n+1)] for i in range(n+1)]
    result = []
    for i,build in enumerate(build_frame):
        if build[3] == 1: # 설치작업
            #설치조건 검사
            if build[2] == 0: # 기둥
                if make_gidoong(board,build[0],build[1]):
                    board[5 - build[1]][build[0]][build[2]] = 1
                    result.append(build[:3])
            else: # 보
                if make_bo(board,build[0],build[1]):
                    board[5 - build[1]][build[0]][build[2]] = 1
                    result.append(build[:3])


        else: # 삭제작업
            if build[2] == 0:  # 기둥
                # 해당 좌표의 모든 것 다 삭제
                board[5 - build[1]][build[0]][0] = 0
                result.remove(build[:3])
                for re in result:
                    if not check_delete(board,re[0],re[1],re[2]) :
                        board[5 - build[1]][build[0]][0] = 1
                        result.append(build[:3])
                        break
            else:  # 보
                board[5 - build[1]][build[0]][1] = 0
                result.remove(build[:3])

                for re in result:
                    if not check_delete(board,re[0],re[1],re[2]):
                        board[5 - build[1]][build[0]][1] = 1
                        result.append(build[:3])
                        break


    result = sorted(result)
    return result

# print(solution(5,[[1,0,0,1],[1,1,1,1],[2,1,0,1],[2,2,1,1],[5,0,0,1],[5,1,0,1],[4,2,1,1],[3,2,1,1]]))
print(solution(5,[[1,0,0,1],[1,1,1,1],[2,1,0,1],[2,2,1,1],[5,0,0,1],[5,1,0,1],[4,2,1,1],[3,2,1,1],[5,1,0,0]]))
print(solution(5,[[0,0,0,1],[2,0,0,1],[4,0,0,1],[0,1,1,1],[1,1,1,1],[2,1,1,1],[3,1,1,1],[2,0,0,0],[1,1,1,0],[2,2,0,1]]))
print(solution(5,[[0,0,0,1],[2,0,0,1],[4,0,0,1],[0,1,1,1],[1,1,1,1],[2,1,1,1],[3,1,1,1],[2,0,0,0],[1,1,1,0],[2,1,1,0]]))