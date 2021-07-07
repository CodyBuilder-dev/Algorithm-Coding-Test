"""
제목 : HTTP 패킷통신 구현 1

요구사항 :
- 입력으로 (문자열,순번)이 적힌 리스트가 주어진다
- 순번에 맞게 문자열을 합친 후 반환하는 프로그램을 만들어라

아이디어 :
(1) 모든 패킷이 한방에 주어지는 경우
- 리스트의 순번을 기준으로 정렬한 후 합친다

(2) 패킷이 순차적으로 주어지는 경우
- 일정 버퍼동안 대기한 후, 해당 버퍼동안의 모든 패킷을 한방에 처리
-> (1)과 동일함

- 실시간으로 패킷을 붙이기
-> PQ에 집어넣고, 끝나면 한방에 뽑는게 맞다

"""
# from collections import deque
from queue import PriorityQueue


def solution(packets):
    packets = sorted(packets, key = lambda x:x[1])
    return ''.join(map(lambda x:x[0],packets))


class TupleQueue:
    def __init__(self):
        self.pq = PriorityQueue()

    def put(self, tuple):
        self.pq.put((tuple[1],tuple[0]))

    def get(self):
        result = self.pq.get()
        return result[1], result[0]

    def empty(self):
        return self.pq.empty()


def solution_realtime(packets):
    pq = TupleQueue()
    for packet in packets:
        pq.put(packet)

    answer = ""
    while not pq.empty():
        answer += pq.get()[0]

    return answer


print(solution([("aaa",2),("bbb",1),("ccc",4),("dddd",3)]))
print(solution_realtime([("aaa",2),("bbb",1),("ccc",4),("dddd",3)]))