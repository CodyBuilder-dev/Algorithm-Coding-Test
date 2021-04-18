"""
제목 : 최적의 행렬 곱셈

아이디어 : DP
(1) 왜 DP로 해야 하는가?
- 왜 그리디가 안되는가?
    - 어디선가 반례가 나올 듯
    - 그리고 애초에 테케에서 안되면 그리디가 아님을 어렴풋이 알 수 있다
- 왜 DP인가?
    - 교과서에 나오는 정석적인 예제
(2) DP를 어떻게 구성할 것인가?
- 우선 바탕이 되는 재귀구조부터 파악
    - 3개씩 묶는다 치면
        - [a,b,c,d,e,f,g]가 있을 때
        - [x,d,e,f,g]
        - [a,x,e,f,g]
        - [a,b,c,x,g]
        - [a,b,c,e,x]
            - [y,e,x]
            - [a,y,x]
            - [a,b,y]
    - 굳이 3개씩 묶지 말고, 그냥 i번부터 j번까지 행렬의 곱셈결과라고 정의하면 된다

- 키와 밸류
    - 키 : 시작점과 종결점
    - 밸류 : 최소 곱셈연산의 수
- 초기값
    - dp[k][k] (자기자신) = 자기자신의 행*열
    - dp[k][k+1] (k번부터 k+1번까지의 최소값) = dp[k][k]*matrix[k+1][1]
- 점화식
    - dp[0][len()] = min(dp[0][0]+dp[1][len()]+계산,
                        dp[0][1]+dp[2][len()]+ 계산
                        dp[0][2]+...)
"""
from math import inf

def recur(matrix,start,end,dp):
    if end == start:
        return 0
    if end == start+1:
        return matrix[end][1]*matrix[start][0]*matrix[start][1]

    minima = inf
    for k in range(start,end):
        if dp[start][k] == -1:
            dp[start][k] = recur(matrix,start,k,dp)
        if dp[k+1][end] == -1:
            dp[k+1][end] = recur(matrix,k+1,end,dp)

        minima = min(minima,dp[start][k]+dp[k+1][end]+matrix[start][0]*matrix[k][1]*matrix[end][1])

    return minima

def solution(matrix_sizes):
    # i번재에서 j번째 인덱스의 행렬까지의 최소값
    dp = [[-1]*len(matrix_sizes) for _ in range(len(matrix_sizes))]

    return recur(matrix_sizes,0,len(matrix_sizes)-1,dp)

# 테스트 케이스
print(solution([[5,3],[3,10],[10,6]]),270)
print(solution([[5,3],[3,10],[10,6],[6,2]]),210)
print(solution([[99,1],[1,98],[98,99],[99,3]]),10296)
print(solution([[5,3],[3,10],[10,6],[6,2],[2,100]]),1210)
print(solution([[5,3],[3,10],[10,6],[6,9999],[9999,2],[2,100]]))

