"""
제목 : 숫자 게임

아이디어 :
- A와 B를 비교
- A보다 +1만큼만 큰 친구 내보내기
- A를 순회하면서, A보다 큰 친구 중 가장 작은 친구 내보내기
    - 정렬 후 Lower Bound로 계산 가능 O(NlogN)

구현 : 돌면서 전략에 의해
-
"""
from bisect import bisect

def solution(A, B):
    B = sorted(B)

    score = 0
    for x in A:
        idx = bisect(B, x)

        # B에 x보다 큰 놈이 len(B) - idx명 있다
        # 즉, 해당 idx번째 놈을 제거하면 된다
        if len(B) - idx > 0:
            B.pop(idx)
            score += 1
        else: # 큰놈이 아무도 없을 경우, 차라리 제일 작은놈을 없애자
            B.pop(0)
    return score


# print(solution([5,1,3,7],[2,2,6,8]),3)
print(solution([6, 1, 3, 7], [2, 2, 6, 8]), 3)
print(solution([2, 2, 2, 2], [1, 1, 1, 1]), 0)
print(solution([1, 2, 3], [1, 3, 2]), 2)
print(solution([1, 3, 5, 7], [2, 2, 2, 4]), 2)
