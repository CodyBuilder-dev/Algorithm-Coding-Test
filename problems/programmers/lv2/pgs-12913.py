"""
제목 : 땅따먹기

아이디어 : 그냥 아무생각없이 완탐하는 경우
- 열 ^ 행 = 4^1 * 3^99999 = 탐색 불가

아이디어 : 그리디?
- 각 열에서 제일 큰 놈을 찾아서 밟는다
-> 딱 봐도 반례가 굉장히 많을 거 같다

아이디어 : DP
- 형태 결정과 조회 방식 결정
    - dp[행][열] = 최대값
    - 마지막에 dp[마지막행] 을 조회해 최대값 찾아내기
- 초기값과 점화식
    - dp[0][0~3] = map[0][0~3]
    - dp[y][x] = max(dp[y][x를 제외한 열]) + map[y][x]

"""

def solution(land):
    dp = [[0]*4 for _ in range(len(land))]
    dp[0] = land[0]

    for i in range(1,len(land)):
        for j in range(4):
            dp[i][j] = max(dp[i-1][:j]+dp[i-1][j+1:]) + land[i][j]
    return max(dp[len(land)-1])

print(solution([[1,2,3,5],[5,6,7,8],[4,3,2,1]]))