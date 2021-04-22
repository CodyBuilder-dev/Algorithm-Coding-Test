"""
제목 : N-Queen

아이디어 : '땅따먹기' 문제와 유사한 DP?
- dp테이블 정의
    - dp[i행][j열] =놓을수 있는 경우의 수
- 초기값
    - dp[0] = [1,1,1,1,1,...]
- 점하식
    - 1번째 행부터 시작한다.- 2번째행부터는, 1번쨰줄의 조건에 안맞는 열을 제외한 열의 최대값
    - dp[i][j] = max(dp[i-1][j 조건에 맞는 열들])

- 결과
-> 틀린 점화식이라 불가능!
"""
def solution(n):
    dp = [[0]*n for _ in range(n)]
    dp[0] = [1] * n

    for i in range(1, n):
        for j in range(n):
            dp[i][j] = sum(dp[i - 1][:j - 1] + dp[i - 1][j + 2:])

    return dp

print(solution(4),2)
print(solution(12))