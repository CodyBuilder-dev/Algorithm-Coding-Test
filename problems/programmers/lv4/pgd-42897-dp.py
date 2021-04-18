"""
제목 : 도둑질

아이디어 : 그리디로 푸는건 안되는걸 확인했다

아이디어 : DP
(1) 어떤 값을 저장할 것인가
- 절대로 겹치지 않는 경우로 나눈다?
    - 0번지의 집을 털면, 1번지의 집은 절대 털 수 없다
    - 반대로 1번지의 집을 털면 0번지의 집은 절대 털 수 없다
- key : [0][j] = 0번지를 털고 j까지 털었을 때 [1][j] = 1번지를 털고 j까지 털엇을 때
- value : 훔칠수 있는 돈의 최대값
(2) 초기값
- dp[0][0] = money[0]
- dp[[1][1] = money[1]
- 나머지 -1 초기화

(3) 점화식
- dp[0][j] = dp[0][j-2]

구현 : 원형이므로 주기성 이용
-길이 l이면 l로 나눈 나머지

유사한 문제 : 스티커 모으기(2)
- 스티커 모으기에 비해 집의 개수가 10배 증가한 문제
"""
def solution(money):
    if len(money) <= 3:
        return max(money)
    dp = [[0]*len(money) for i in range(2)]
    dp[0][0] = money[0]
    dp[1][0] = 0
    dp[1][1] = money[1]

    for i in range(1,len(money)-1):
        dp[0][i] = max(dp[0][i-2]+money[i],dp[0][i-1])
        dp[1][i] = max(dp[1][i-2]+money[i],dp[1][i-1])
    i += 1 # len(money) - 1
    dp[0][i] = max(dp[0][i-1],dp[0][i-2])
    dp[1][i] = max(dp[1][i-2]+money[i],dp[1][i-1])
    return max(map(max,dp))

# 테스트 케이스
print(solution([1,2,3,1]), 4)
print(solution([1,1,4,1,4]), 8)
print(solution([1000,0,0,1000,0,0,1000,0,0,1000]), 3000)
print(solution([1000,1,0,1,2,1000,0]), 2001)
print(solution([1000,0,0,0,0,1000,0,0,0,0,0,1000]), 2000)
print(solution([1,2,3,4,5,6,7,8,9,10]), 30)
print(solution([0,0,0,0,100,0,0,100,0,0,1,1]), 201)
print(solution([11,0,2,5,100,100,85,1]), 198)
print(solution([1,2,3]), 3)
print(solution([91,90,5,7,5,7]), 104)
print(solution([90,0,0,95,1,1]), 185)