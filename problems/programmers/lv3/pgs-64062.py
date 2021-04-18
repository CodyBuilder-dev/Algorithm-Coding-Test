"""
제목 : 징검다리 건너기

아이디어 : 이분탐색
- n개의 돌에 대해 k만큼 뛴다고 하자
- 돌에 적힌 숫자의 최대값이 결국 사람의 최대값이다
- 즉, 0명~최대값까지가 이분탐색 범위이다

- mid에서 시작해서, mid명이 건널수 있는지 아래와 같이 판단한다
    - mid이상인 돌을 모두 찾는다
    - 해당 돌들의 인덱스 차이를 검사한다
    - k 초과시 실패한다
- 검사결과에 따라 mid를 조정한다
    - 가능시 mid를 늘린다
    - 불가능시 mid를 줄인다
"""
from bisect import bisect_left
def solution(stones, k):
    max_people = max(stones)

    sorted_stones = sorted([[v,i] for i,v in enumerate(stones)])

    left, right = 0,max_people

    while left <= right:
        i = bisect_left(sorted(stones),(left + right)//2)

        prev = -1
        is_available = True
        available_idx = sorted(map(lambda x: x[1], sorted_stones[i:]))
        for idx in available_idx:
            if idx - prev > k:
                is_available = False
                break
            else:
                prev = idx
        if len(stones) - idx > k:
            is_available = False

        if is_available:
            mid = (left + right) // 2 #될 때만 mid를 저장하고 아니면 저장하지 않는다. 왜냐? mid를 반화해야 하기 때문
            left = mid+1

        else:
            right = (left + right) // 2 - 1

    return mid

# 테스트 케이스
print(solution([2, 4, 5, 3, 2, 1, 4, 2, 5, 1],3))
print(solution([1],1))
print(solution([2],1))
print(solution([100],1),100)
print(solution([100,99],1),99)
print(solution([100,99],2),100)
# 25개의 돌에 k칸씩 점프
print(solution([1,1,1,1, 2, 4, 5, 3, 2, 1, 4, 2, 5, 1,1,1,1,1,1,1,1,1,1,1,1],2),1)
print(solution([1,1,1,1, 2, 4, 5, 3, 2, 1, 4, 2, 5, 1,1,1,1,1,1,1,1,1,1,1,1],4),1)
print(solution([1,1,1,1, 2, 4, 5, 3, 2, 1, 4, 2, 5, 1,1,1,1,1,1,1,1,1,1,1,1],5),1)

