"""
제목 : 약수의 합

아이디어 : 브루트 포스
- N의 약수를 구하려면, sqrt(N)까지의 모든 수를 나눠본다
"""
def solution(n):
    divisor = set()
    for i in range(1,int(n**0.5)+1):
        if n%i == 0:
            divisor.add(i)
            divisor.add(n//i)
    return sum(divisor)

print(solution(12))