"""
제목 : 다음 큰 숫자

아이디어 : n+1 ~ 1,000,000 사이의 모든 수를 검사
- 검사할 수를 이진수로 바꾼다
- 1의 개수를 비교한다
    - n과 1의 개수가 동일할 경우 해당 수를 반환한다
    - n과 1의 개수가 다를 경우 다음 수로 넘어간다
"""

def solution(n):
    num_of_1 = bin(n).count('1')

    # for i in range(n+1,1000000): # 경계조건 생각 안한 실수!
    for i in range(n+1,2*n+1):
        if bin(i).count('1') == num_of_1 :
            return i

# 테스트 케이스
print(solution(78),83)
print(solution(15),23)
print(solution(1),2)
print(solution(2),4)
print(solution(999999),1000031)
print(solution(1000000),1000064)
print(solution(10),12)
