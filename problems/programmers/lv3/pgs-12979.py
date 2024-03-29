"""
제목 : 기지국 설치

아이디어 : N<= 200,000,000이므로 스위핑조차 불가능하다
-> 반드시 수학적으로 일반화하는 법을 찾아내야 함

아이디어 : 커버 범위를 이해
- (W,빈칸)
    - (1,1) = 1
    - (1,2) = 1
    - (1,3) = 1
    - (1,4) = 2
    - ...
    - (1,6) = 2
    - (1,7) = 3
    -> 즉, 빈칸이 X칸일때 필요한 기지국의 수는 (X)//(2W+1)
    - (2,11) = 3
    - (2,10) = 2
    - (2,7) = 2
    - (2,6) = 2
    - (2,5) = 1
    - (2,4) = 1
    ...
- 기지국을 경계로, 구간을 찾아낸다
    - left는 가장 왼쪽의 빈칸을 나타낸다
    - mid는 현재 기지국의 가장 왼쪽을 나타낸다
    - right는 현재 기지국 다음의 빈칸을 나타낸다
"""
def solution(n, stations, w):
    # 아랫부분에서 마무리 처리를 잘 해줬다면, 이 부분은 필요가 없다
    # if n == 1 and not stations:
    #     return 1

    left, mid, right = 1, 1, 1
    total = 0
    for s in stations:
        left = right
        mid = s - w
        right = s + w + 1
        total += (mid - left + 2 * w) // (2 * w + 1)

    # 마지막에서 남는 것이 있다면 끝까지 처리해주기
    if right <= n:
        total += (n - right + 1 + 2 * w) // (2 * w + 1)
    return total

# 테스트 케이스
# print(solution(11,[4,11],1),3)
print(solution(16,[9],2),3)