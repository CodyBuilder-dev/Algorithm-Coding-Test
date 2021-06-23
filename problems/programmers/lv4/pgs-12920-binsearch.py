"""
제목 : 선입 선출 스케줄링

아이디어 : 이분탐색 효율화
- 꼭 미리 할당총량 배열을 만들어놓고 이분탐색할 필요는 없다
- mid가 정해지면, 그때그때 할댱량을 계산해서 n과 비교할 수 있다

구현 : 이분탐색 범위판정을 구현해야 한다\
- upper bound를 구한다
- upper bound의 정의상, upper bound직전과의 코어 개수 차이를 구한다
- 해당 코어개수만큼 cores를 돌면서, 할당받은 친구를 구한다 
"""
def solution(n, cores):
    left = 0
    right = len(cores)*10000

    while left < right:
        mid = (left + right)//2

        received_jobs = 0
        for core in cores:
            received_jobs += mid//core + 1

        if received_jobs < n:
            left = mid + 1
        else:
            right = mid

    received_jobs = 0
    for core in cores:
        received_jobs+= left//core + 1
    # print("최초로 뛰어넘는 시점은",left,"해당시점 총 예약 건수는",received_jobs)

    received_jobs_before = 0
    for core in cores:
        received_jobs_before += (left-1)//core + 1

    # print("그전 시점은", mid, "해당시점 총 예약 건수는", received_jobs_before)
    received_core_cnt = min(received_jobs,n) - received_jobs_before
    for i, core in enumerate(cores):
        if left % core == 0:
            received_core_cnt -= 1
        if received_core_cnt == 0:
            return i+1


print(solution(6,	[1,2,3]))
print(solution(7,	[1,2,3]))
