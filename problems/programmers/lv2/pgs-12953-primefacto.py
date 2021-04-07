"""
제목 : N개의 최소공배수


아이디어 : 소인수분해?
- 각 수의 소인수를 dictionary에 넣는다
- 소인수들의 최대값을 모아 곱한다
"""

def eratosthenes(num):
    prime = dict.fromkeys(range(2,num),True)
    for i in range(2,int(num**0.5)+1):
        for j in range(i*i,num+1,i):
            if not j % i: prime[j] = False

    return {k:0 for k,v in prime.items() if v}


def prime_factorization(num,prime):
    prime_cp = prime.copy()
    for p in prime_cp:
        while num%p == 0 and num >1:
            num = num//p
            prime_cp[p]+=1

    return prime_cp

def mult(values: list) -> int:
    if not values:
        return 1
    return values[0]*mult(values[1:])

def solution(arr):

    prime = eratosthenes(100)
    prime_min = dict.fromkeys(prime.keys(),0)

    for num in arr:
        if num == 1: continue
        prime_temp = prime_factorization(num, prime)

        for p in prime_temp:
            if prime_temp[p] >= prime_min[p]:
                prime_min[p] = prime_temp[p]
    return mult([k**v for k,v in prime_min.items()])






# 테스트 케이스
# print(eratosthenes(100))
# print(mult([1,3,5,7,9]))
print(solution([2,6,8,14]),168)
print(solution([2,3,5]),30)
print(solution([3, 4, 9, 16]), 144)
