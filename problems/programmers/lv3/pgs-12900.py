"""
제목 : 2 x n 타일링

아이디어 : 분할정복 + DP?
- 절대 겹칠 수 없는 경우로 나눈다?
    - 해보면 알겠지만 중복이 굉장히 많이 된다
    - 중복이 일어나는 조건을 정확히 정의하거나
    - 아니면 아예 시작부터 절대 겹칠 수 없도록 분할해서 센다
- 점화식 찾기
    - 1차원 DP이긴 한데, 홀짝이 다른 DP이다
    - dp[1] = 1
    - dp[2] = 2이다
    - dp[3] = dp[1] + dp[2]
    - dp[4] = dp[2] + do[3]
"""

def solution(n):

    dp=[0]*(n+1)
    dp[0] = 1
    dp[1] = 1

    for i in range(2,n+1):
        dp[i] = dp[i-2] + dp[i-1]

    return dp[n]

for i in range(1,10):
    print(solution(i))