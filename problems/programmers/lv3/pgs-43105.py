"""
제목 : 정수 삼각형

아이디어 : 경로를 직접 따라가며 구현
-> 2^500이므로 당연히 불가능

아이디어 : DP를 써야 한다
- 무엇을 저장할 것인가?
    - 해당 위치까지 오는 최대 값
    - 특정 경로에 도달하는 방법은 결국 2가지뿐
    - 왼쪽 위의 최대값 + 오른쪽 위의 최대값
        -가장 왼쪽인 경우는 오른족 위
        -가장 오른쪽인 경우는 왼쪽 위
- 어떻게 저장할 것인가? :
    - 제일 왼쪽과 오른쪽부터 계산
    - 가운데는 이를 바탕으로 계산
구현 :
- 왼쪽 오른쪽 채우기
    - for i in range(n) :
        - dp[i][0] = dp[i-1][0]+tri[i][0]
        - dp[i][i] =  dp[i-1][i-1]+tri[i][i]
- 가운데 채우기
    - for i in range(n):
        -for j in range(i) :
            dp[i][j] = max(dp[i-1][j-1],dp[i-1][j])+tr[[i][j]

- 최대값 반환

"""
def solution(triangle):
    depth = len(triangle)
    dp = [[0]*depth for i in range(depth)]

    for i in range(depth):
        if i == 0 :
            dp[i][0] = triangle[i][0]
            continue
        dp[i][0] = triangle[i][0] + dp[i-1][0]
        dp[i][i] = triangle[i][i] + dp[i-1][i-1]

    for i in range(2,depth):
        for j in range(i):
            dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + triangle[i][j]

    return max(dp[depth-1])

print(solution([[7], [3, 8], [8, 1, 0], [2, 7, 4, 4], [4, 5, 2, 6, 5]]),30)
