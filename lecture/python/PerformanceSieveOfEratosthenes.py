import time


def logging_time(original_fn):
    def wrapper_fn(*args, **kwargs):
        start_time = time.time()
        result = original_fn(*args, **kwargs)
        end_time = time.time()

        print("WorkingTime[{}]: {} sec".format(original_fn.__name__, end_time - start_time))

        return result

    return wrapper_fn


@logging_time
def eratos_dict_fromkeys(num: int):
    # dict를 fromkeys로 구현
    prime = dict.fromkeys(range(2, num + 1), True)

    for i in range(2, int(num ** 0.5) + 1):
        for j in range(i * i, num + 1, i):
            prime[j] = False

    # 0, 1은 소수가 아니다
    prime[0], prime[1] = False, False

    return prime


@logging_time
def eratos_dict(num: int):
    # 빈 dict로 구현
    prime = dict()

    for i in range(2, int(num ** 0.5) + 1):
        for j in range(i * i, num + 1, i):
            prime[j] = False

    # 0, 1은 소수가 아니다
    prime[0], prime[1] = False, False

    return prime


@logging_time
def eratos_list(num: int):
    # dict 대신 list로 구현
    prime = [True] * (num + 1)

    for i in range(2, int(num ** 0.5) + 1):
        if prime[i]:
            for j in range(i * i, num + 1, i):
                if prime[j]: prime[j] = False

    # 0, 1은 소수가 아니다
    prime[0], prime[1] = False, False

    return prime


@logging_time
def eratos_set(num: int):
    # set으로 구현
    prime = set(range(2, num + 1))

    for i in range(2, int(num ** 0.5) + 1):
        prime -= set(range(i * i, num + 1, i))

    # 0, 1은 소수가 아니다
    prime -= set([0, 1])

    return prime

@logging_time
def solution(n):
    num=set(range(2,n+1))

    for i in range(2,n+1):
        if i in num:
            num-=set(range(i*i,n+1,i))
    return num

@logging_time
def get_primes(max_int):
    numbers = range(2, max_int)
    while len(numbers) > 0:
        # only keep numbers that are NOT divisible bythe prime
        numbers = [num for num in numbers if num %
                   numbers[0] != 0 or num == numbers[0]]
        yield numbers[0]  # yield the prime
        # make a new numbers-array, the first num is  a new prime
        numbers = numbers[1:]



@logging_time
def eratos_slice(limit):
    is_prime = [False] * 2 + [True] * (limit - 1)
    for n in range(int(limit**0.5 + 1.5)): # stop at ``sqrt(limit)``
        if is_prime[n]:
            v = ((limit - n * n) // n + 1)
            is_prime[n*n::n] = [False] * v
    return [i for i, prime in enumerate(is_prime) if prime]



# 시간 측정
# eratos_dict_fromkeys(100000)
# eratos_dict(100000)
eratos_list(100000)
eratos_set(100000)
eratos_slice(100000)
solution(100000)

start_time = time.time()
lst = [i for i in get_primes(100000)]
end_time = time.time()
print("WorkingTime[generator]: {} sec".format(end_time - start_time))

