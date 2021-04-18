"""
제목 : 단어 퍼즐

아이디어 : 거스름돈과 비슷한 dp
(1) DP 값 저장
- key는 strs의 i번재 단어까지 서서 t의 j번째를 만드는 것
    - j번째 까지냐 vs j번째 만이냐
- value는 최소값

(2) 초기화
- dp[0][0] ~ dp[0][len(t)-1]는 초기화할 수 있음

(3) 점화식
- dp[i][j] 는, min(dp[i-1][j], dp[i][j-k] (k = strs에 담긴 원소들의 길이))인가?

"""
from math import inf

def solution(strs, t):
    dp = [[inf]*len(t) for _ in range(len(strs))]
    for i in range(len(t)):
        print(strs[0]*(i+1))
        dp[0][i] = t[:i+1].count(strs[0]*(i+1))

    return dp

# 테스트 케이스
print(solution(["ba","na","n","a"],"banana"),3)
print(solution(["app","ap","p","l","e","ple","pp"],"apple"),2)
print(solution(["ba","an","nan","ban","n"],"banana"),-1)
print(solution(["bax","dxv","zxc"],"baobab"))
print(solution)