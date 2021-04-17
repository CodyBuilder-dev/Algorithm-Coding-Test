"""
제목 : 점프와 순간 이동

아이디어 : 비트마스크

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