"""
제목 : 소수 찾기

아이디어 : 에라토스테네스의 체를 그대로 사용하면 된다
"""
from functools import reduce

def eratosthenes(num: int)-> dict:
    prime = dict.fromkeys(range(2,num+1),True)
    for i in range(2,int(num**0.5)+1):
        for j in range(i*i,num+1,i):
            prime[j] = False

    return prime

def solution(n):
    prime = eratosthenes(n)
    return reduce(lambda acc,x:acc+prime[x],prime,0)