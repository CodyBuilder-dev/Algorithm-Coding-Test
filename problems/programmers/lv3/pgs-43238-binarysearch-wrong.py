"""
제목 :입국 심사

아이디어 : 사고 순서의 전환 + 이분 탐색
- 먼저 사람을 배분한 후 시간을 계산하지 말고, 시간을 쭉 나열한 후 그 중에 배열이 되는 것을 찾자
    - 어차피 가능한 시간 범위는 1~max(times)*n이다
- 시간을 쭉 나열해 두고 그중에서 실제 사람이 들어갈 수 있는 건만 찾자
    - 가능한가의 여부는... 결국 부분수열의 합의 심화판?

- 시간복잡도
    - 이분 탐색을 하는 경우의 수 O(logN) = 대략 30?
    - 각 탐색마다 도는 경우의 수 O(len(times)) = 대략 10^5

구현
- 시간을 줄이는 방법
    -
"""
from bisect import bisect_left,bisect_right

def solution(n, times):
    times = sorted(times) # O(NlogN)
    available_time = [i for i in range(1,n*times[-1]+1)]

    # left,right = 0, len(available_time)
    left, right = 0, available_time[-1]

    while left <= right :
        # 이걸 왜 넣어줘야 할까?
        if left == right : return right
        mid = (left+right) // 2

        # 0. 단순 list comprehension -> 여기가 병목
        # available_people = sum([available_time[mid]//time for time in times])

        # 1. 가지치기 : for문 돌면서 초과하면 바로 break -> 병목 축소 불가
        # available_people = 0
        # for time in times :
        #     if available_people >= n : break
        #     available_people += available_time[mid] // time

        # 2. index기반 탐색이 아니라 값 기반 탐색으롭 변경
        available_people = 0
        available_people = sum([mid // time for time in times])

        # 결과에 따른 처리
        if n <= available_people: right = mid
        else: left = mid + 1
        # print(available_time[mid])
    return mid

print(solution(6,[7,10]))
print(solution(2,[1,2]))

