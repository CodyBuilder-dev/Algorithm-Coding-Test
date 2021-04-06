"""
제목 : 가장 큰 정사각형 찾기

아이디어 : DP
- 내 위쪽, 오른쪽, 오른쪽 위 3칸만 보면 된다
    - 왜냐? 도형이 정사각형이고, 그 3칸이 내게 필요한 모든 정보를 다 갖고있기 때문
- 판정 절차
    - 경계에 위치한 칸인 경우, 볼것도 없이 자기자신 대입
    - 자기자신이 0인 경우 볼것도 없이 0
    - 자기자신이 1인 경우
        - 3칸에 0이 하나라도 있으면 1
        - 3칸에 다 1이상이면
            - 3칸 중 최소값의 제곱근의 +1을 해서 제곱

"""
def solution(board):
    height = len(board)
    width = len(board[0])
    dp = [[987654321]*width for i in range(height)]
    
    
    for i in range(height):
        for j in range(width):
            if i == 0 or j == 0 or board[i][j] == 0: # 경계 조건 처리
                dp[i][j] = board[i][j]
                continue
            if board[i][j] == 1 :
                surround = [dp[k][j-1:j+1] for k in range(i-1,i+1)] # 주변 배열
                dp[i][j] = (int(min(map(min, surround))**0.5) + 1)** 2
            
    return max(map(max, dp))

print(solution([[0,1,1,1],[1,1,1,1],[1,1,1,1],[0,0,1,0]]),9)
print(solution([[0,0,1,1],[1,1,1,1]]),	4)
