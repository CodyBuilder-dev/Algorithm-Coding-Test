"""
제목 : 점프와 순간 이동

아이디어 : DP
- 최대 거리가 10억이므로, 이동하는 모든 경로를 다 완탐할 수 없다
- 각 거리까지 도달하기 위한 연료의 최소값의 점화식을 찾자
    - 각 거리까지 도달하는 방법은, k칸 점프하거나, n//2에서 순간이동 하는 것이다
    - dp[n] = min(dp[n-k]+k,dp[n//2])

구현 :
- 그냥 2로 나누다가 홀수면 -1해서 반복
"""
def solution(n):
    count = 1
    while n > 1:
        if n%2:
            count+=1
            n = n-1
        else:
            n //= 2
    return count

print(solution(5))
print(solution(6))
print(solution(5000))
print(solution(999_999_999))
print(solution(1_000_000_000))