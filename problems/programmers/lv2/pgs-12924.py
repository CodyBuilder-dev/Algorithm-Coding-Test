"""
제목 : 숫자의 표현

아이디어 : 왠지 약수와 관계있는것 같은데?
- 약수를 구함
    - 1 : 모든수에 대해 무조건
    - 2 : 3이상 홀수에 대해서만
    - 3579 : 모든 수에 대해서 경우의 수 존재
    - 468... : 짝수는 무시
    - n : 무시
- 정리
    - 홀수인 경우 : 자기를 제외한 모든 약수 + 1개 더
    - 짝수인 경우 : 자기를 제외한 약수 중 홀수인거만 ,
    - 소수인 경우, : 자기를 제외한 약수 중 홀수인거
예제 :
(1) 15
1 3 5 15 + 2
O O O X    O

(2) 64
1 2 4 8 16 32 64
O X X X X X   X

(3) 48
1 2 3 6 8 16 24 48
O X O X X X X  X
(3) 소수 13
1 13
O X
"""
def find_divisor(n):
    result = []
    for i in range(2,n):
        if n%i == 0: result.append(i)
    return result

def solution(n):
    if n == 1: return 1
    cnt =1
    divisor = find_divisor(n)
    for d in divisor:
        if d%2 and d != n:
          cnt+=1
    return cnt+1 if n%2 else cnt

# 테스트 케이스
# print(find_divisor(15))
print(solution(15))
print(solution(1))
print(solution(10000))
print(solution(45))
print(solution(22))