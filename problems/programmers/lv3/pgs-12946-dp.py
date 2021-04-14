"""
제목 : 하노이의 탑

아이디어 : 일반식이 존재할 것 같은데
- 하노이의 탑은 결국 아래와 같은 반복 구조를 갖는다
    - 가장 낮은 원판을 제외한 모든 원판을 한칸 옆으로 옮긴 후
    - 가장 낮은 원판을 끝으로 옮긴다
    - 나머지 원판에 대해서, 위에서 했던 과정을 반복한다
- 일반화하면 아래와 같다
    - hanoi[n] = hanoi[n-1] + 1 + hanoi[n-1]
    - hanoi[1] = 1
    - hanoi[2] = 3
    - hanoi[3] = 7
- 그러나 문제는, 하노이의 탑의 갯수가 아니라 하노이의 탑의 과정을 반환하라는 것
    - 즉,
구현 : 리스트를 반환하는 재귀로 구현
    - 반환값의 형식이 list의 계층 구조이므로, append와 extend에 주의
"""
def hanoi(n: int,start: int, end: int, dp:list)-> list:
    if n == 1: return [[start,end]]
    mid = 6 - start - end

    answer = []
    if not dp[n-1][start][mid]:
        dp[n - 1][start][mid] = hanoi(n-1,start,mid,dp)
    answer.extend(dp[n-1][start][mid])

    answer.extend(hanoi(1,start,end,dp))

    if not dp[n-1][mid][end]:
        dp[n-1][mid][end] = hanoi(n-1,mid,end,dp)
    answer.extend(dp[n - 1][mid][end])

    return answer

def solution(n):
    dp = []
    for i in range(n+1):
        dp.append([[None]*4 for j in range(4)])

    return hanoi(n,1,3,dp)

for i in range(1,10):
    print(solution(i))