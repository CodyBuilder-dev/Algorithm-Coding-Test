"""
제목 : 예상 대진표

아이디어 :
(1) 이기는 경우의 번호 처리
- 홀수는 n//2+1
- 짝수는 n//2
(2) 서로 만나는 경우의 번호 관계
- a와 b의 차이가 1이고, 2로 나눈 몫의 절대값이 1 차이나는 경우에 만남

구현 : 비트마스크로 구현
"""
def solution(n,a,b):
    return ((a-1)^(b-1)).bit_length()

print(solution(8,4,7))

print(9&5)
print((9&5).bit_length())
# print(7 & 5.bit_length())
print((3^6).bit_length())