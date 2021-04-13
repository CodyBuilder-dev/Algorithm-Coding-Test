"""
제목 : 수식 최대화

아이디어 :
(1) 처음에 돌면서 연산자 쭉 센다
- 정규표현식과 Counter?
(2) 연산자부터 처리한다
    - 내 연산이 있으면 처리하고, 없으면 그냥 다른 deque에 옮긴다
(3) 모든 연산자에 대해 위의 과정을 반복한다

구현 : 그냥 리스트로 구현
- ops[0]은 numbers[0]과 numbers[1]에 적용된다
- list에서 remove하는 식으로 구현
-> 물론 list의 삽입삭제는 시간이 오래 걸릴 수 있지만, 어차피 길이가 100이니 감수할 만 하다
"""

from itertools import permutations
import re


def solution(expression):
    ops_orders = list(permutations(['+','-','*']))

    result = 0
    for order in ops_orders:
        numbers = re.split("[+\-*]", expression)
        ops = re.split("\d+", expression)[1:-1]

        for op in order:
            while op in ops:
                idx = ops.index(op)
                eq = numbers.pop(idx)+ops.pop(idx)+numbers.pop(idx)
                numbers.insert(idx,str(eval(eq)))

        result = max(result,abs(int(numbers[0])))

    return result

# 테스트 케이스
print(solution("100-200*300-500+20"),60420)
print(solution("177-661*999*99-133+221+334+555-166-144-551-166*166-166*166-133*88*55-11*4+55*888*454*12+11-66+444*99"),6083974714)
print(solution("2-990-5+2"),995)
print(solution("50*6-3*2"),300)