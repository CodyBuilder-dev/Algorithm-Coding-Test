"""
제목 : 예상 대진표

아이디어 :
(1) 이기는 경우의 번호 처리
- 홀수는 n//2+1
- 짝수는 n//2
(2) 서로 만나는 경우의 번호 관계
- a와 b의 차이가 1이고, 2로 나눈 몫의 절대값이 1 차이나는 경우에 만남
"""
def solution(n,a,b):
    i = 1
    while True :
        if (a//2 - b//2 == 1 and a-b ==1) \
            or (b//2 - a//2 ==1 and b - a == 1):
            return i
        a = a//2+1 if a%2 else a//2
        b = b//2+1 if b%2 else b//2
        i+=1

    return i

print(solution(8,4,7))