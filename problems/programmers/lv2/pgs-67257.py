"""
제목 : 수식 최대화

아이디어 :
(1) 처음에 돌면서 연산자 쭉 센다
- 정규표현식과 Counter?
(2) 연산자부터 처리한다
    - 내 연산이 있으면 처리하고, 없으면 그냥 다른 deque에 옮긴다
(3) 모든 연산자에 대해 위의 과정을 반복한다

구현 : 디큐
"""
from collections import deque
from itertools import permutations
import re


def solution(expression):
    ops_orders = list(permutations(['+','-','*']))

    for order in ops_orders:
        numbers = re.split("[+\-*]", expression)
        ops = re.split("\d+", expression)[1:-1]

        dq = deque()
        dq.append(numbers.pop(0))

        for op in order:
            new_dq = deque()

        # while len(ops) and len(numbers):
        #     first = dq.pop()
        #     op = ops.pop(0)
        #     second = numbers.pop(0)
        #
        #     # 높은 우선순위 검사
        #     op_idx = order.index(op)
        #     if sum([1 if ops_counter[_] > 0 else 0 for _ in order[:op_idx]]):
        #         dq.append(op)
        #         dq.append(second)
        #     else:
        #         ops_counter[op] -= 1
        #         first = dq.pop()
        #         dq.append(eval(first+op+second))


    # return dq

# 테스트 케이스
print(solution("100-200*300-500+20"))
print(solution("177-661*999*99-133+221+334+555-166-144-551-166*166-166*166-133*88*55-11*4+55*888*454*12+11-66+444*99"),6083974714)
print(solution("2-990-5+2"),995)