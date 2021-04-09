"""
제목 : 기지국 설치

구현 : math.ceil() 함수를 사용하면 어떨까?
"""
import math

def solution(n, stations, w):
    left, mid, right = 1, 1, 1
    total = 0
    for s in stations:
        left = right
        mid = s - w
        right = s + w + 1
        total += math.ceil((mid - left) / (2 * w + 1))

    # 마지막에서 남는 것이 있다면 끝까지 처리해주기
    if right <= n:
        total += math.ceil((n - right + 1) / (2 * w + 1))
    return total

# 테스트 케이스
# print(solution(11,[4,11],1),3)
print(solution(16,[9],2),3)
