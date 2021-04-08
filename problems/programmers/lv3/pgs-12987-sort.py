"""
제목 : 숫자 게임

아이디어 : 정렬
- 어차피 승자의 인덱스정보는 필요없고, 몇번 이겼는지만 계산하면 됨
- A와 B 둘다 정렬 이후 비교
"""
from collections import deque

def solution(A,B):
    A, B = sorted(A), sorted(B)
    score = 0
    for x in A:
        for j,y in enumerate(B):
            if x < y:
                score +=1
                B.pop(j)
                break
            if j == len(B)-1:
                B.pop(0)
    return score

# 테스트케이스
print(solution([5,1,3,7],[2,2,6,8]),3)
print(solution([6, 1, 3, 7], [2, 2, 6, 8]), 3)
print(solution([2, 2, 2, 2], [1, 1, 1, 1]), 0)
print(solution([1, 2, 3], [1, 3, 2]), 2)
print(solution([1, 3, 5, 7], [2, 2, 2, 4]), 2)
