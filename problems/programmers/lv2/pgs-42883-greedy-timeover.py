"""
제목 : 큰 수 만들기

아이디어 : 그리디
- 앞에 잘못 푼 문제와 동일

구현 : 역시 문제 해결중 수시로 문자열이 변하므로 deque가 가장 편하다
- 유사한 문제가 카카오에서 출제된 적 있음
- 근데 중간에 있는것도 빼야 되는데? list를 써야될 수도 있음
- deque를 중간에 바꾸는 과정에서 더 오래 걸림
-> 그러나, push pop하는 과정에서 시간이 오래 걸려 시간초과 걸림
"""
from collections import deque

def solution(number,k):
    n = len(number)
    number = list(number)
    # number = deque(number)

    max_idx = number.index(max(number))
    answer = []
    # answer = deque()

    while k > 0 and len(answer) <= n-k:
        if max_idx > k: #너무 많아 못 지움
            max_idx = number.index(max(number[:max_idx]))

        else: #지울 수 있음
            k -= max_idx
            # 여기때매 pop되는거 아닌지 의심됨
            for i in range(max_idx):
                number.pop(0)

            # answer.append(number.pop(0))
            answer.append(number.pop(0))

            if len(number):
                max_idx = number.index(max(number))

    return ''.join((answer + number)[:n-k])




# 테스트케이스
print(solution("1924",2),"94")
print(solution("1231234", 3),"3234")
print(solution("4177252841",4),"775841")
print(solution("321",2))
print(solution("21",1))
print(solution('77777', 1))