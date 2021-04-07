"""
제목 : N개의 최소공배수


아이디어 : 여러개의 최소 공배수를 구하는 법
(1) 잘못된 방법
- 최대공약수를 구한다
- 각 수의 최대공약수로 나눈 나머지를 다 곱한다
-> 반례 : 1 2 4 8
    - 실제 최소공배수는 8
    - 계산되는 최소공배수는 64
(2) 잘못된 방법
- 최대공약수를 구한다
    - 구해지면, 그놈을 제외하고 나머지는 그놈으로 나눈다
    - 구해지지 않으거나 원소가 하나뿐이면 다 곱하고 종료한다
- 남은 놈들끼리 다시 최대 공약수를 구해서 반복한다

- 1 2 4 8
-   2 4 8 (1)
-     2 4 (2)
-       2 (2)

- 2 6 8 14
-   3 4 7 (2)
-> 반례 : 3, 4, 9, 16
    - 4개 숫자는 서로소
    - 실제 최소공배수는 1XX
    - 계산되는 최소공배수는 1XXX
(3) 소인수분해?
- 각 수의 소인수를 dictionary에 넣는다
- 최소만 남겨서 판다

구현 :
(1) N개의 최대공약수를 구하는 법
- 어차피 O(15*100)

(2) 빼고 다음 부분을 반복하는 법
- stack이나 deque 이용
"""
from math import gcd

def find_gcd(arr):
    for i in range(min(arr), 0, -1):
        if len(list(
                filter(
                    lambda x: x > 0,
                    map(
                        lambda x: x % i,
                        arr
                    )
                )
        )
        ) == 0:
            return i


def solution(arr):
    stack = []
    while True:
        gcd = find_gcd(arr)
        if len(arr) <= 1: break  # 서로소
        if gcd == 1 and 1 not in arr: break  # 서로소
        stack.append(gcd)
        arr.remove(gcd)
        arr = list(map(lambda x: x // gcd, arr))

    total = 1
    for num in stack + arr:
        total *= num
    return total


# print(find_gcd([1,3,6,12]))
# print(find_gcd([2,3,5]))
print(solution([2,6,8,14]),168)
print(solution([2,3,5]),30)
print(solution([3, 4, 9, 16]), 144)
