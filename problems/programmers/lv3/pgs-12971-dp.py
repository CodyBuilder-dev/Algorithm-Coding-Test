"""
제목 : 스티커 모으기

아이디어 : 완탐?
- 10^5^2이므로 불가

아이디어 : 분할정복과 2차원 DP
- 첫번째 스티커를 뜯으면, 두번째 스티커는 절대 뜯을 수 없다
    - 두가지로 분류
- 각 경우에 대해 DP를 수행한다
    - dp[0][...]
    - d[[1][...]로 푸는듯?
- dp테이블을 채워넣는 식을 생각해낸다
    - 내 한칸 옆의 스티커를 가지면, 나랑 그 옆 스티커를 못 가진다
    - 내 스티커를 떼면, 그 옆 2칸 스티커를 가질 수 있다
"""

def solution(sticker):
    if len(sticker) <= 3:
        return max(sticker)
    dp = [[0]*len(sticker) for i in range(2)]
    dp[0][0] = sticker[0]
    dp[1][0] = 0
    dp[1][1] = sticker[1]

    for i in range(1,len(sticker)-1):
        dp[0][i] = max(dp[0][i-2]+sticker[i],dp[0][i-1])
        dp[1][i] = max(dp[1][i-2]+sticker[i],dp[1][i-1])
    i += 1 # len(sticker) - 1
    dp[0][i] = max(dp[0][i-1],dp[0][i-2])
    dp[1][i] = max(dp[1][i-2]+sticker[i],dp[1][i-1])
    return max(map(max,dp))

print(solution([14, 6, 5, 11, 3, 9, 2, 10]))
print(solution([1, 3, 2, 5, 4]))
print(solution([2]))
print(solution([2,4]))
print(solution([4,5,6]))
# print([True,False,False].index(False))
