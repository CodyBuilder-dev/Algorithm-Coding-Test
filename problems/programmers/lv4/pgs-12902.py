"""
제목 : 3 x n 타일링

아이디어 : DP
"""

def solution(n):
    dp = [0] * (n+1)
    dp[0] = 1
    dp[2] = 3
    for i in range(4,n+1):
        dp[i] += dp[i - 2] * 3
        for j in range(0,i-2,2):
            dp[i] += dp[j] * 2

    return dp[n]

# 테스트 케이스
print(list(range(0,10-2,2)))