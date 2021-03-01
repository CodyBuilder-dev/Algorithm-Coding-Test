import math
import time

"""
소인수분해를 수행하는 함수 구현
input : n
output : dict with prime:order
"""


# 단순 반복
def factorize1(n):
    result = {}
    i = 2
    while (i <= n ** 0.5):
        if n % i == 0:
            result[i] = result[i] + 1 if result.get(i) else 1
            n /= i
            i = 2
        else:
            i += 1

    if (n > 1): result[n] = result[n] + 1 if result.get(n) else 1
    result[1] = 1

    return result


def factorize1_ans(n):
    result = {}
    # sqrtn = math.floor(math.sqrt(n)) # 내가 보기엔 이놈이 병목임
    sqrtn = int(n**0.5)
    for i in range(2, int(n**0.5) + 1):
        while n % i == 0: # 여기서 엄청난 부하가 걸리는 듯
            result[i] = result[i] + 1 if result.get(i) else 1
            n = n//i
            # n /= i

    if (n > 1): result[n] = result[n] + 1 if result.get(n) else 1
    result[1] = 1

    return result


# 에라토스테네스의 체
# 2부터 root(n)까지 다 검사하지 말자
# 그 안에 있는 소수만 검사하자

"""
input : n
output : True(소수) False(합성수)
"""
def is_prime(n) :
    for i in range(2,int(n**0.5) + 1):
        if n % i == 0 :
            return False

    return True

"""
input : n
output : (1,n) 사이의 소수 리스트
"""
def find_primes(n) :
    result = []
    for i in range(2, n+1) :
        if is_prime(i) : result.append(i)
    return result

def factorize2(n) :
    pass

"""
input : n (=p*q, p와 q는 소수)
output : p,q
"""
def shore(n) :
    for i in range(2,n) :
        # gcd 찾기
        # gcd != 1이면 종료, gcd == 1이면 다음으로

        # r찾기
        # r 짝수면 다시 gcd찾기
        if (r % 2 == 0 ) :


"""
input : a,b
output : gcd(a,b)
desc : math.gcd로 대체 가능
"""


"""
input : a,N
output : r (주기)
"""
def find_period(a,N) :



if __name__ == '__main__':


    # 큰 수의 소인수분해
    # start = time.time()
    # n = 2 ** 512 - 1
    # print(factorize1_ans(n))
    # # print(factorize1(n))
    # end = time.time()
    # print(end - start)

    # 소수 확인
    # print(is_prime(101))
    print(find_primes(101))
# See PyCharm help at https://www.jetbrains.com/help/pycharm/
