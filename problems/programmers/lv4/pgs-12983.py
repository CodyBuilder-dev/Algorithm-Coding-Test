"""
제목 : 단어 퍼즐

아이디어 : DP
- DP에 저장할 내용
    - n번째 자리까지 만들 때 드는 단어의 최소값
    - n은 1부터 시작
- 점화식
    - dp[n] = min( (1자리 단어가 존재시) dp[n-1]+1
            , (2자리 단어가 존재시) dp[n-2]+1
            , (3자리 단어가 존재시) dp[n-3]+1
            , ....
최적화 :
    - strs의 모든원소의 길이는 1이상 5이하이므로, in을 사용하면 5번만 훑어볼 수 있다
"""
from math import inf

def solution(strs, t):
    dp = [inf]*(len(t)+1)

    # dp테이블 초기화
    dp[0] = 0

    for i,c in enumerate(t, start=1):
        for j in range(1,6):
            if t[i - j:i] in strs:
                dp[i] = dp[i-j] + 1 if dp[i-j] + 1 < dp[i] else dp[i]


    return dp[len(t)] if dp[len(t)] != inf else -1

print(solution(["ba","na","n","a"],	"banana"))
print(solution(["app","ap","p","l","e","ple","pp"],	"apple"))
print(solution(["ba","an","nan","ban","n"],	"banana"))
