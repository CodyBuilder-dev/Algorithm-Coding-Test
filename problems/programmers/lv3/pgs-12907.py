"""
제목 : 거스름돈

아이디어 : 전형적인 DP
- 최소값이 아니라, 모든 경우의 수임에 주의한다
    - 단순히 더하지 말고 중복을 고려해야 한다
        - 211과 112와 121은 동일하다
- 2차원 DP
    - 자세한 아이디어는 Notion에 정리
"""
def solution(n, money):
    money = sorted(money)
    # dp = [1 if i in money else 0 for i in range(n+1)]
    dp = [[0]*(n+1) for _ in range(len(money))]
    # 첫번째 동전으로 계산 가능한 모든 경우 넣기
    for i in range(money[0],n+1,money[0]):
        dp[0][i] = 1
    dp[0][0] =1 
    # 이후로 쭉 나아가기

    for i in range(1,len(money)):
        for j in range(n+1):
            if j-money[i] >= 0:
                dp[i][j] = dp[i][j-money[i]] % 1_000_000_007 + dp[i-1][j] % 1_000_000_007
            else:
                dp[i][j] = dp[i-1][j] % 1_000_000_007
    return dp[len(money)-1][n] % 1_000_000_007

print(solution(5,[1,2,5]),4)
print(solution(100,[2,3,7,10]))