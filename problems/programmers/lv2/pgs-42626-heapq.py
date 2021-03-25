"""
제목 : 더 맵게

아이디어 :
- 맵기의 강도가 가장 작은 2개를 뽑아서 계산해야 한다
- 매 반복마다 순서가 바뀌므로 정렬을 유지해줘야한다
    - 그렇다고 매 반복마다 N*logN의 정렬을 수행하면 N*N*logN > N^2으로 비효율적이다
    - 자료구조 자체에 정렬이 유지되는 것을 사용해야 하고, 이것이 바로 우선순위 큐이다

구현 :
- 리스트를 오름차순 PQ에 집어넣는다
- PQ의 루트를 확인한다
    - 루트가 K보다 크면, PQ의 모든 값이 K보다 크다는 뜻이므로 종료
    - 루트가 K보다 작으면,
        - PQ의 원소 수가 1인 경우, 더이상 매워질 수 없으므로 -1 반환하고 종료
        - PQ의 원소 수가 2 이상인 경우, 연산을 수행한다.
"""
import heapq

def solution(scoville, K):
    heap = []
    for i in scoville:
        heapq.heappush(heap,i)
    cnt = 0

    while len(heap) >= 1 :
        smallest = heapq.heappop(heap)

        if len(heap) < 1 and smallest < K : return -1
        if smallest >= K : return cnt
        second = heapq.heappop(heap)
        heapq.heappush(heap,smallest + second*2)
        cnt += 1

    return cnt