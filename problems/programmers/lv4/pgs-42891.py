"""
제목 : 무지의 먹방 라이브

아이디어 : 직접 구현?
-> 시간이 최대  2*10^13이라 쉽지 않다

아이디어 : 주기성
- 주기성을 이용하는 문제
    - 그런데 주기가 변한다?
    - 변하는 주기에 따라 k의 구간을 나눈다

- 구간 분할 방법
    - 음식을 (시간,인덱스+1)의 오름차순으로 정렬한다
        - food_times = [(1,2),(2,3),(3,1),(3,4),(6,5),(7,6),(7,7),(7,8),(10,9)]
    - 0초 ~ l* food_times[0] -1 까지는 주기가 l
        - 0 ~ 8초
    - l * food_times[0]초 ~ l * food_times[0] + (l - 1)*(food_times[1]-food_times[0])
        - 9초 ~ 16초 (8+8)
        - 17초 ~ 23초 (16+7)
        - 24초 ~ 38초 (23+5*3)
        - 39초 ~ 42초 (38+4*1)
        - 43초 ~ 45초 (42+1*3)
예제
    - food_times = [1,2,2,3,4,6,6,6,10]
    - 0 ~ 8초
    - 9 ~ 16초 (8+8*1)
    - 17 ~ 22초 (16+6*1)
    - 23 ~ 27초 (22+5*1)
    - 28 ~ 35초 (27+4*2)
    - 36 ~ 39초 (35+1*4)

구현 : deque를 이용
(1) boundary계산
- boundary = [] # 구간의 마지막 숫자를 저장
- boundary.append(food_times[0]*len(food_times) - 1)

- while food_times > 1:
    l = len(food_times)
    first = food_times.popleft()
    second = food_times.popleft()

    if first == second:
        food_times.pushleft(second)
        continue
    boundary.append(boundary[-1] + (second-first)*(l-1))

(2) k판정
- 몇번째 싸이클인지 확인한다 -> 해당 사이클의 주기의 나머지만큼
- 예시
    - b = 3, k = 2 -> 해당 사이클의 주기는 4다. k % 4 = 2 return 2+1
    - b = 2, k = 1 -> 해당 사이클의 주기가 1인 경우  k % 1 = 0 -> return 0+1
"""
from collections import deque

def solution(food_times, k):
    sorted_food_times = sorted([(t,i) for i,t in enumerate(food_times,start=1)])
    dq = deque(sorted_food_times)
    second = dq.popleft()
    boundary = [(second[0]*len(sorted_food_times)-1,len(sorted_food_times))]

    # (1) 바운더리 설정
    while len(dq) >= 1:
        first = dq.popleft()
        first,second = second,first
        if first[0] == second[0]:
            continue
        l = len(dq) + 1
        boundary.append((boundary[-1][0] + l*(second[0]-first[0]),l))
    # (2) k 판정
    for i,b in enumerate(boundary):
        if k <= b[0]:
            rest_index = sorted(x[1] for x in sorted_food_times[-1*b[1]:])
            return rest_index[-1*((b[0]-k)%b[1])-1]
    return -1


# 테스트 케이스
print(solution([3, 1, 2],5),1)
print(solution([2,4],2),1)
print(solution([1,2,2,3,4,6,6,6,10],4),5)
print(solution([1,2,2,3,4,6,6,6,10],8),9)
print(solution([1,2,2,3,4,6,6,6,10],9),2)
print(solution([1],0),1)
print(solution([3],1),1)
print(solution([3,2,4,5,4,6,7,4],20),6)
print(solution([1,2],1))
print(solution([1,2],2))
print(solution([1,2],3)) # k가 범위를 초과하는 경우
print(solution(food_times=[4,2,3,6,7,1,5,8],k=16),3)
print(solution(food_times=[4,2,3,6,7,1,5,8],k=27),5)
print(solution([7,8,3,3,2,2,2,2,2,2,2,2],k = 35),2)
print(solution([1, 5, 5, 5, 5, 6, 7], 31),6)
print(solution(food_times = [1,1,1,1],k=4),-1)
print(solution([3,1,1,1,2,4,3],12),6)
print(solution([4, 3, 5, 6, 2], k=7),3)