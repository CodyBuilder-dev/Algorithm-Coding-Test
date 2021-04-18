"""
제목 : 최적의 행렬 곱셈

아이디어 : 재귀(진짜 재귀로 풀수 있는 것은 아니고, DP를 위한 점화식 연습용이다)
- recur(N개의 행렬들) = min( 선택된 3개 행렬 연산결과 + recur(세개의 결과행렬 + 나머지 N-3개의 행렬들))
- 언제 반복되는지 문제를 파악하기

결과 : 역시나 시간초과
- 연쇄행렬 곱셈의 가능한 경우의 수는 카탈란 수이다
    - C(n) = 1/(n+1) * combination(2n,n)
"""
def calc_tri(matrix_three):
    a,b,c = matrix_three
    left = a[0] * c[0] * (a[1] + c[1])
    right = a[1] * c[1] * (a[0] + c[0])

    eq = left - right
    return right if eq > 0 else left

def recur(matrixies):
    if len(matrixies) < 2:
        return 0
    if len(matrixies) == 2:
        a,b = matrixies
        return a[0]*a[1]*b[1]

    result = []
    for i in range(len(matrixies)-2):
        a,b,c = matrixies[i:i+3]
        result.append( calc_tri(matrixies[i:i+3])
                       + recur(matrixies[:i] + [[a[0],c[1]]] + matrixies[i+3:]) )
    return min(result)

def solution(matrix_sizes):
    return recur(matrix_sizes)

# 테스트 케이스
print(solution([[5,3],[3,10],[10,6]]),270)
print(solution([[5,3],[3,10],[10,6],[6,2]]),210)
print(solution([[99,1],[1,98],[98,99],[99,3]]),10296)
print(solution([[5,3],[3,10],[10,6],[6,2],[2,100]]),1210)
print(solution([[5,3],[3,10],[10,6],[6,9999],[9999,2],[2,100]]))

