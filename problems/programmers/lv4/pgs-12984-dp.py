"""
제목 :지형 편집

아이디어 : DP?
- 점화식
    - 0 11 222 344
    - 0층은 Q * (1*2 + 2*3 + 3*1 + 4*2)
    - 1층은 0층 + P * (0*1) - Q(1*2)
    - 2층은 1층 + P * (1*2) - Q(2*3)
"""
from math import inf
from bisect import *

def solution(land, P, Q):
    flatten_land = []
    for row in land:
        flatten_land += row
    n = len(flatten_land)
    flatten_land = sorted(flatten_land)
    total_block = sum(flatten_land)
    min_height = flatten_land[0]
    max_height = flatten_land[-1]

    # 모든 층에 대해 비용을 계산
    cost = Q*(total_block - n*min_height)
    min_cost = cost

    # for h in range(min_height+1, max_height+1):
    #     lower = bisect_left(flatten_land, h)
    #     cost += P*lower - Q*(n - lower)
    #     min_cost = cost if cost < min_cost else min_cost
    for i,h in enumerate(flatten_land[1:],start=1):
        if h == flatten_land[i-1]:
            continue
        cost += P*i*(h-flatten_land[i-1]) - Q*(n- i)*(h-flatten_land[i-1])
        min_cost = cost if cost < min_cost else min_cost
    return min_cost



print(solution([[1, 2], [2, 3]],	3,	2))
print(solution([[4, 4, 3], [3, 2, 2], [ 2, 1, 0 ]],	5,	3))
print(solution([[100]],3,2))
print(solution([[2,2],[2,2]],100,100))
print(solution([[1,1_000_000_000],[4,27]],100,99))


import random
big_case = [[random.randrange(1_000_000_001)]*300 for _ in range(300)]
big_p =random.randrange(101)
big_q = random.randrange(101)

print(solution(big_case,big_p,big_q))