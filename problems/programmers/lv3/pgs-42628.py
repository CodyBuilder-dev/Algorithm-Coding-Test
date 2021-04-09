"""
제목 : 이중우선순위큐

아이디어 : 자료구조 2개를 만들어서 동시에 관리한다?
- 최대힙 1개, 최소힙 1개를 만든 후 최대값은 최대힙, 최소값은 최소힙에서 뺀다
-> 자료구조를 2개의 데이터를 정합성있게 관리하는게 쉽지 않을 듯

아이디어 : 자료구조 1개를 만들되, insert 할때부터 순서를 잘 지켜서 집어넣자
- 새로운 수가 들어오면, 반드시 lower bound를 계산해서 삽입위치를 선정한다
- 최대값을 뺄 때는, 가장 마지막 원소를 제거한다
- 최소값을 뺄 때는, 가장 앞부분 원소를 제거한다

구현 : 클래스로 구현
- 맨 앞자리가 I인 경우,insert()를 호출한다
- 맨 앞자리가 D인 경우,delete(num)을 호출해 제거한다
"""

from bisect import bisect_left

class DoublePriorityQueue:
    def __init__(self,queue=[]):
        self.queue = sorted(queue)

    def _insert(self,num):
        idx = bisect_left(self.queue,num)
        self.queue.insert(idx,num)

    def _delete(self,flag):
        if flag == -1:
            self.queue.pop(0)
        else:
            self.queue.pop(-1)

def solution(operations):
    dpq = DoublePriorityQueue()

    for op in operations:
        if op[0] == 'I':
            dpq._insert(int(op[1]))
        if op[1] == 'D':
            dpq._delete(int(op[1]))
    return dpq.queue[-1],dpq.queue[0]