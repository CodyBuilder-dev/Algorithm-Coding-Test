"""
제목 : 수식 최대화

아이디어 :
(1) 처음에 돌면서 연산자 쭉 센다
- 정규표현식과 Counter?
(2) 앞에서부터 파싱해서 넣는다
    - 나보다 높은 우선순위 연산자가 있으면 연산안한다
    - 나보다 높은 우선쉰위연산자가 없으면 그냥 바로 계산해서 집어넣는다
(3) 스택에 마지막으로 남은 숫자들 다 처리하고 합을 낸다
(4) 3!겨웅에 대해 반복한다

구현 : 디큐
"""
from collections import Counter, deque
from itertools import permutations
import re


def solution(expression):
    ops_orders = list(permutations(['+','-','*']))

    for order in ops_orders:
        numbers = re.split("[+\-*]", expression)
        ops = re.split("\d+", expression)[1:-1]
        ops_counter = dict.fromkeys(order,0)
        for op in ops:
            ops_counter[op] +=1

        dq = deque()
        dq.append(numbers.pop(0))

        while len(ops) and len(numbers):
            first = dq.pop()
            op = ops.pop(0)
            second = numbers.pop(0)

            # 높은 우선순위 검사
            op_idx = order.index(op)
            if sum([1 if ops_counter[_] > 0 else 0 for _ in order[:op_idx]]):
                dq.append(op)
                dq.append(second)
            else:
                ops_counter[op] -= 1
                first = dq.pop()
                dq.append(eval(first+op+second))


    return dq

# 테스트 케이스
print(solution("100-200*300-500+20"))
print(solution("177*999-661*99-133+221+334+555-166-144-551-166*166-166*166-133*88*55-11*4+55*888*454*12+11-66+444*99"),6083974714)
print(solution("2-990-5+2"),995)