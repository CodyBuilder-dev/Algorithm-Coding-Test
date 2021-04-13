"""
제목 : 점프와 순간 이동

아이디어 : DP
- 최대 거리가 10억이므로, 이동하는 모든 경로를 다 완탐할 수 없다
- 각 거리까지 도달하기 위한 연료의 최소값의 점화식을 찾자
    - 각 거리까지 도달하는 방법은, k칸 점프하거나, n//2에서 순간이동 하는 것이다
    - dp[n] = min(dp[n-k]+k,dp[n//2])

구현 :
- 바텀업으로 하려면, dp[n]을 구하기 위해 dp[n-k]를 전부 뒤지므로 비효율
- 탑다운으로 하되, 먼저 dp를 살펴보고 구하는 걸로
-> dp를 저장해두면 메모리가 매우 부족함
"""
MAX_RANGE = 125_000_000
dp = [0,1,1]+[0]*(MAX_RANGE-3)

def solution(n):
    if n == 1 or n == 2:
        return 1

    if n%2:
        return solution(n-1)+1

    temp = 987_654_321

    if dp[n//2]:
        temp = min(temp,dp[n//2])
    else:
        dp[n//2] = solution(n//2)
        temp = min(temp,dp[n//2])

    return temp

print(solution(5))
print(solution(6))
print(solution(5000))
print(solution(999_999_999))
print(solution(1_000_000_000))