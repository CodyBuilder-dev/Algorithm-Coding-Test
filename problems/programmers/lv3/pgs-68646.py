"""
제목 : 풍선 터뜨리기

아이디어 : 작은 번호를 터뜨리는건 0회 또는 1회
- 무조건 사는 규칙
    - 나의 양쪽에 나보다 작은 놈이 있으면 안된다

구현
(1) 그냥 매번 내 양쪽을 다 검사한다
-> O(n^2) = 10^12 -> 시간초과

(2) 한번의 스위핑으로 해결
- 전체 최소값을 찾는다
- idx = 1 부터 찾기 시작한다
    - 왼족보다 크면 바로 탈락
    - 왼쪽보다 작으면 최소값 갱신 및 생존
- idx =2 도 본다
    - 왼쪽 최소값보다 크면 바로 탈락
    - 왼쪽보다 작으면 최소값 갱신 및 생존
- idx=3..
- idx=최소값
    - 무조건 산다
- 오른족부터 찾기 시작한다
"""
def solution(a):
    survive = [True]*len(a) #O(n)
    min_idx = a.index(min(a)) # O(n)

    left_min = a[0]
    for i in range(1,min_idx):
        if a[i] > left_min: survive[i] = False
        else: left_min=a[i]

    right_min = a[-1]
    for i in range(len(a)-1,min_idx,-1):
        if a[i] > right_min: survive[i] = False
        else: right_min=a[i]

    return survive.count(True) # O(n)



print(solution([9,-1,-5]))
print(solution([-16,27,65,-2,58,-92,-71,-68,-61,-33]))
