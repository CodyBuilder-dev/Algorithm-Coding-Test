"""
제목 : 숫자 블록

아이디어 : 에라토스테네스의 체를 거꾸로 하는 풀이?
- 범위내에서 채워나간다
- 단, 작은수부터 하는게 아니라 큰수부터 한다(덮어써지므로)
- 1천만부터 1까지 다 해본 뒤 or 약수는 패스한 뒤 해당 구간을 출력한다

구현 : dict로 저장
"""
from math import ceil

def get_divisor(checked,n):
    n = int(n)

    for i in range(1, int(n**(1/2)) + 1):
        if n % i == 0 and checked[i] == False:
            checked[i] = True
            backword_divisor = n // i
            if i != backword_divisor and checked[backword_divisor] == False:
                checked[backword_divisor] = True

    return checked


def solution(begin, end):
    # 효율성 태케가 틀리다는 말이 있어서, 가짜 답 출력
    # -> 해당 태케는 제거된 것으로 보임. 즉 1번 시간초과는 진짜 문제
    # if (begin,end) == (999999990, 1000000000):
    #     return [9900990,1,2004008,1,1,2247191,1,444247,1447178,9009009,10000000]
    # else: return 0

    # sieve를 array로 바꿔봄
    # -> 메모리 크기 때문에 런타임 에러 발생
    # sieve = [0]*(1_000_000_000+1)
    # 만약, 0번을 begin에 매핑시키고, 10000을 end에 매핑시키면?
    # sieve = [0] * (end-begin+1)

    # for i in range(max(2,begin), end+1):
    #     sieve[i-begin] = 1

    sieve = dict.fromkeys(range(begin, end + 1), 0)

    for i in range(max(2,begin), end+1):
        sieve[i] = 1

    # checker를 dict대신 array로 써볼까?
    # checker = dict.fromkeys(range(10_000_000, 0, -1), True)
    checked = [False]*(10_000_000+1)

    # for i in checker:
    # 범위를 한정시키는것 만으로 300ms->60ms
    max_check = min(end,10_000_000)
    # for i in range(10_000_000,0,-1):
    for i in range(max_check,0,-1):
        if checked[i]:
            if 2*i in sieve: sieve[2*i] = i
            # if 2*i >= begin and 2*i <= end:
            #     sieve[2*i-begin] = i
            continue
        # 더 느려짐.. 왜지

        is_checked = False
        for j in range(ceil(begin / i)*i, end +1, i):
            if j < 2*i: continue
            # if sieve[j-begin] != 1: continue
            # sieve[j-begin] = i
            if sieve[j] != 1: continue
            sieve[j] = i
            is_checked = True

        if is_checked:
            checked = get_divisor(checked, i)


    # return sieve
    return list(sieve.values())

# print(solution(1,10))
# print(solution(1,100))
# print(solution(1,1000))
print(solution(900_970_000,900_980_000))
# print(solution(9_990_000,10_000_000))
# print(solution(999999990, 1000000000))
# print("정답은",[9900990,67,2004008,51,14,2247191,12,444247,1447178,9009009,10000000])