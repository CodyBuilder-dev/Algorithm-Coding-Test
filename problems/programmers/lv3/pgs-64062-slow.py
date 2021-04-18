"""
제목 : 징검다리 건너기


"""
from math import ceil,inf

def solution(stones, k):
    # min_stone = ceil(len(stones)/k)
    min_stone = len(stones)//k

    max_friends = -inf
    sorted_stones = sorted([[v,i] for i,v in enumerate(stones)])
    for i in range(min_stone,len(stones)+1):
        prev = -1
        is_available = True
        available_idx =sorted(map(lambda x:x[1],sorted_stones[-1*i:]))
        for idx in available_idx:
            if idx - prev > k:
                is_available = False
                break
            else:
                prev = idx
        if len(stones) - idx >k:
            is_available = False
        if is_available:
            return sorted_stones[-i][0]

    return sorted_stones[-1][0]

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
