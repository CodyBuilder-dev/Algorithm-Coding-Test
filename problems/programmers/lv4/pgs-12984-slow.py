"""
제목 :지형 편집

아이디어 : 정렬되지 않은 데이터의 최소값을 이분탐색
- 층-비용 그래프를 그려보면, 무조건 극소값이 1개인 그래프이다
    - 왜냐? 비용은 p*쌓는블록 + q*빼는블록인데, 층이 높아질수록 쌓는 블록은 증가하고 빼는 블록은 감소하므로
- 큐 + 이분탐색

구현 :
- left right로부터 mid를 구한다
- right = mid로 한번, left = mid로 한번 구한다
- mid가 left right보다 둘다 작으면 큐에 넣는다
"""
from collections import deque
from math import inf

def solution(land, P, Q):
    def calc_cost(height):
        cost = [list(map(lambda x:P*(height-x) if height >= x else Q*(x-height), row)) for row in land]
        return sum(map(sum,cost))

    min_height = min(map(min,land))
    max_height = max(map(max, land))

    if min_height == max_height:
        return 0

    q = deque()
    left = min_height
    right = max_height

    q.append((left, right))

    min_cost = inf
    while q:
        left, right = q.popleft()
        if left < right:
            mid = (left + right) // 2
            if min([calc_cost(left),calc_cost(right),calc_cost(mid)]) > min_cost:
                continue

            min_cost = calc_cost(mid) if calc_cost(mid) < min_cost else min_cost

            q.append((left, mid))
            q.append((mid+1, right))


    return min(min_cost,calc_cost(min_height),calc_cost(max_height))

# print(solution([[1, 2], [2, 3]],	3,	2))
# print(solution([[4, 4, 3], [3, 2, 2], [ 2, 1, 0 ]],	5,	3))
# print(solution([[100]],3,2))
# print(solution([[2,2],[2,2]],100,100))
print(solution([[1,1_000_000_000],[4,27]],100,99))


import random
big_case = [[random.randrange(1_000_000_001)]*300 for _ in range(300)]
big_p =random.randrange(101)
big_q = random.randrange(101)

print(solution(big_case,big_p,big_q))