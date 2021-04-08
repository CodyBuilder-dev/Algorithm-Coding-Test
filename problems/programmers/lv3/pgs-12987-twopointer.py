from collections import deque

def solution(A,B):
    A, B = sorted(A), sorted(B)
    score = 0

    while A:
        if A[-1]<B[-1]: # 제일 큰놈끼리 붙어서 이기면 큰놈 제거
            score += 1
            A.pop()
            B.pop()
        else: # 지면, 아예 제일 작은놈 제거
            A.pop()
            B.pop(0)

    return score

# 테스트케이스
print(solution([5,1,3,7],[2,2,6,8]),3)
print(solution([6, 1, 3, 7], [2, 2, 6, 8]), 3)
print(solution([2, 2, 2, 2], [1, 1, 1, 1]), 0)
print(solution([1, 2, 3], [1, 3, 2]), 2)
print(solution([1, 3, 5, 7], [2, 2, 2, 4]), 2)