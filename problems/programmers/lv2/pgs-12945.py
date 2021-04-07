"""
제목 : 피보나치 수

아이디어 : 가장 기초적인 1차원 DP
"""


def solution(n):
    dp = [0, 1]
    for i in range(2, n + 1):
        dp.append(dp[i - 1] % 1234567 + dp[i - 2] % 1234567)
    return dp[n]

print(solution(3))
print(solution(5))