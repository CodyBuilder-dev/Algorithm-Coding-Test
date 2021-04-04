"""
제목 : 멀리뛰기

아이디어 : 전형적인 1차원 DP
- DP[1] = 1, DP[2] = 2
- DP[n] = DP[n-1] + DP[n-2]

구현 : 리스트나 딕셔너리 중 편한 것으로 구현하면 된다
- 1부터 n까지 순차적으로 DP테이블을 구한다
- DP[n]의 값을 구한다
"""

def solution(n):
    dp = {}
    dp[1] = 1
    dp[2] = 2
    for i in range(3,n+1):
        dp[i] = (dp[i-1] + dp[i-2])%1234567

    return dp[n]

