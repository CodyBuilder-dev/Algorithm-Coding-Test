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
"""
from math import inf

def solution(strs, t):
    dp = [inf]*(len(t)+1)

    # dp테이블 초기화
    dp[0] = 0

    for i,c in enumerate(t, start=1):
        for word in strs:
            if word.endswith(c) and t[i - len(word):i] == word:
                dp[i] = dp[i-len(word)] + 1 if dp[i-len(word)] + 1 < dp[i] else dp[i]


    return dp[len(t)] if dp[len(t)] != inf else -1

print(solution(["ba","na","n","a"],	"banana"))
print(solution(["app","ap","p","l","e","ple","pp"],	"apple"))
print(solution(["ba","an","nan","ban","n"],	"banana"))
