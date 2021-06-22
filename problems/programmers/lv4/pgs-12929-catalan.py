"""
제목 : 올바른 괄호의 갯수

아이디어 : 카탈란 수로 풀린다는걸 알고 풀면 어처구니 없을 정도로 쉽게 풀린다
(자세한 증명에 대한 공부는 블로그에)

구현 : 점화식 구현
"""
def solution(n):
    if n == 1: return 1
    c = [None] * (n+1)
    c[0] = 1
    c[1] = 1
    c[2] = 2

    for i in range(2,n):
        c[i+1] = sum([c[j]*c[i-j] for j in range(i+1)])

    return c[n]

print(solution(1))
print(solution(4))
print(solution(14))