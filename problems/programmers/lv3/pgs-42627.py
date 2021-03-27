"""
제목 : 디스크 컨트롤러

아이디어 : 디스크 스케쥴러를 구현하는 문제
- 스케줄링 방식은 두가지이다
    1. 현재 작업이 없는 경우에는, 제일 먼저 들어오는걸 제일 먼저 처리한다
    2. 현재 작업중이고 여러개가 쌓여있는 경우에는, 아래와 같다
        2-1 쌓여 있는 것 중에서 제일 빨리 끝나는걸 수행한다
        2-2 들어온 순서대로 수행한다
    - 어떤게 제일 빠른지를 수학적으로 증명하기는 쉽지 않다
- 그냥 2-1이 제일 빠르다고 가정하고, 알고리즘을 짜자
    -

구현 :
- 시작시점에 제일 빠른 걸 찾아 수행한다
- 시작시점이 현재 JOB의 종료시점보다 작은 친구들을 뽑는다
- 그 친구들을 실행시간순으로 정렬한다
- 실행시간이 가장 짧은 친구를 선택한다
- 전체 친구들은 대기시간을 추가한다
- 해당 친구를 실행시키고 위의 과정을 반복한다
"""
from collections import deque
from queue import PriorityQueue

class CustomPriorityQueue(PriorityQueue):
    def _put(self, item):
        return super()._put((self._get_priority(item), item))

    def _get(self):
        return super()._get()[1]


    def _get_priority(self, item):
        return item[1]

def solution(jobs):
    sorted_by_start = deque(sorted(jobs))
    job_queue = CustomPriorityQueue()


    total_req_res_time = 0

    first_job = sorted_by_start.popleft()
    current_time = first_job[0]
    job_queue._put(first_job)

    while job_queue.qsize() > 0 :
        current_job = job_queue._get()
        while len(sorted_by_start) > 0 :
            next = sorted_by_start.popleft()
            if next[0] > current_time+current_job[1] :
                sorted_by_start.appendleft(next)
                break
            job_queue._put(next)

        # 연산처리
        current_time += current_job[1]
        total_req_res_time += current_job[1]
        total_req_res_time += sum([min(current_time - job[1][0],current_job[1]) for job in job_queue.queue])

        # 만약 연속해서 오는 작업이 없다면, 다음 sorted_by_start.popleft에서 옮긴다
        if job_queue.qsize() == 0 and len(sorted_by_start) > 0:
            next = sorted_by_start.popleft()
            current_time = next[0]
            job_queue._put(next)


    answer = total_req_res_time//len(jobs)
    return answer

# 테스트케이스
# print(solution([[0, 3], [1, 9], [2, 6]]),9)
# print(solution([[0, 10], [2, 10], [9, 10], [15, 2]]), 14)
# print(solution([[0, 10], [2, 12], [9, 19], [15, 17]]), 25)
# print(solution([[0, 3], [1, 9], [2, 6]]), 9)
# print(solution([[0, 1]]), 1)
# print(solution([[1000, 1000]]), 1000)
# print(solution([[0, 1], [0, 1], [0, 1]]), 2)
# print(solution([[0, 1], [0, 1], [0, 1], [0, 1]]), 2)
# print(solution([[0, 1], [1000, 1000]]), 500)
# print(solution([[100, 100], [1000, 1000]]), 550)
# print(solution([[10, 10], [30, 10], [50, 2], [51, 2]]), 6)
# print(solution([[0, 3], [1, 9], [2, 6], [30, 3]]), 7)
# print(9, solution([[0, 3], [1, 9], [2, 6]]))
# print(9, solution([[1, 10], [3, 3], [10, 3]]))
# print(15,solution( [[0, 10], [4, 10], [5, 11], [15, 2]]))
# print(10,solution( [[0, 10]]))
# print(9, solution([[0, 3], [1, 9], [2, 6], [4, 3]]))
# print(3, solution([[0, 1], [1, 2], [500, 6]]))
# print(6, solution([[0, 3], [1, 9], [500, 6]]))
# print(1, solution([[0, 1], [0, 1], [1, 0]]))
# print(3, solution([[0, 3], [4, 3], [8, 3]]))
# print(3, solution([[0, 3], [4, 3], [10, 3]]))
print(3, solution([[0, 5], [6, 2], [6, 1]]))
print(3, solution([[0, 5], [6, 1], [6, 2]]))
# print(5, solution([[0, 5], [2, 2], [5, 3]]))
# print(5, solution([[0, 5], [2, 2], [4, 2]]))
# print(4, solution([[0, 3], [0, 1], [4, 7]]))
# print(3, solution([[0, 2], [3, 6], [3, 1]]))
# print(6, solution([[0, 5], [1, 2], [5, 5]]))
# print(13,solution( [[0, 9], [0, 4], [0, 5], [0, 7], [0, 3]]))
print(72,solution( [[24, 10], [28, 39], [43, 20], [37, 5], [47, 22], [20, 47], [15, 2], [15, 34], [35, 43], [26, 1]]))
print(72,solution( [[24, 10], [28, 39], [43, 20], [37, 5], [47, 22], [20, 47], [15, 34], [15, 2], [35, 43], [26, 1]]))
# print(13,solution( [[1, 9], [1, 4], [1, 5], [1, 7], [1, 3]]))
# print(13,solution( [[0, 9], [0, 4], [0, 5], [0, 7], [0, 3]]))
# print(9, solution( [[0, 3], [1, 9], [2, 6], [4, 3]]))