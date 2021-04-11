"""
제목 : 큰 수 만들기

아이디어 : 그리디
- 앞에 잘못 푼 문제와 동일

구현 : 스택
- 앞의 수보다 작거나 같으면 그냥 넣는다
- 앞의 수보다 크면, 나보다 같거나 큰놈을 만날떄까지 k를 줄이며 계속 뺀다
- k = 0이면, stack과 number를 합쳐서 출력한다
- k가 남으면 최대 길이만큼만 출력한다
"""
from collections import deque

def solution(number,k):
    n = len(number)
    # stack,number = [],list(number)
    stack, number = deque(), deque(number)
    # stack.append(number.pop(0))
    stack.append(number.popleft())
    while k > 0 and len(stack) < n and number:
        while stack and k > 0 and stack[-1] < number[0]:
            stack.pop()
            k -= 1
        # stack.append(number.pop(0))
        stack.append(number.popleft())
    if k > 0: return ''.join(list(stack)[:n-k])
    else: return ''.join(stack + number)



# 테스트케이스
print(solution("1924",2),"94")
print(solution("1231234", 3),"3234")
print(solution("4177252841",4),"775841")
print(solution("321",2))
print(solution("21",1))
print(solution('77777', 1))