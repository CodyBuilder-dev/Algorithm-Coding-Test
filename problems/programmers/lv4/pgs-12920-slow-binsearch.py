"""
제목 : 선입 선출 스케줄링

아이디어 : 이분탐색?
- 유사한 스케쥴링 문제가 이분탐색으로 풀렸다
- 이분탐색의 기준점 : n초일 때 각 코어가 새로 할당받은 누적 건수
    - task를 처리한 시간? task를 할당받은 시간?
    -> 문제에서 할당받는걸 구해야 하므로, 할당받은 시간으로 해야된다
    - 0초부터 할 것인가? 1초부터 할 것인가?
    -> 할당은 0초부터 이루어지므로 0부터
    - 0일때 3개, 1일때 4개, 2일때 6개
- 이분탐색 판단방법
    - 할당받은 개수가 n보다 작다가 갑자기  n보다 같거나 커지는 시점
    - 해당 시점이 배수인 친구들 중 k번쨰
- 할당받은 총 개수는 어떻게 구할 것인가?
    -

구현 : 이분탐색 범위판정(bisect)를 구현해야 한다
-> 비효율적인 구현으로 인해 이분탐색임에도 불구하고 시간초과가 발생한다
"""

from bisect import bisect_left

def solution(n, cores):
    received_jobs = [0]*n*10000
    for i in range(len(received_jobs)):
        received_jobs[i] = sum([1 for c in cores if i%c == 0 ])

    for i in range(1,len(received_jobs)):
        received_jobs[i] = received_jobs[i-1] + received_jobs[i]


    time = bisect_left(received_jobs,n)
    if time >1:
        received_core_cnt = received_jobs[time] - received_jobs[time-1]
    else:
        received_core_cnt = len(cores)


    for i,core in enumerate(cores):
        if time%core == 0:
            received_core_cnt -= 1
        if received_core_cnt == 0:
            return i+1


print(solution(6,	[1,2,3]))
