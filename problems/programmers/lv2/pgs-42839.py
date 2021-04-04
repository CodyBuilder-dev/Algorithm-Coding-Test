"""
제목 : 소수 찾기

아이디어 : 에라토스테네스의 체
(1) 미리 범위를 정해 에라토스테네스의 체로 소수를 찾아둔다

(2) 모든 수를 만들어 가면서 소수의 개수를 찾는다
- n개 중에 1개,2개,3개...를 뽑아 숫자를 만들어야 함
- 재귀로 찾는게 맞는듯
"""

def eratos(num: int)-> dict:
    prime = dict.fromkeys(range(2,num+1),True)
    for i in range(2,int(num**0.5)+1):
        for j in range(i*i,num+1,i):
            prime[j] = False
    return prime


def solution(numbers):
    answer = 0
    return answer