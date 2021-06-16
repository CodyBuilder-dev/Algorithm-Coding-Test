"""
제목 : 가장 먼 노드

아이디어 :
(1) 다익스트라를 이용해 각 노드까지의 모든 거리를 구한다
- 인접 행렬을 이용해 표현
- while 모든 점을 다 확인했을 때 or 다음 확인할 점이 안 나올 때
    - 현재점에서 연결된 점을의 d를 갱신
    - 다음 확인할 점을 heap으로부터 선택
(2) 모든 노드까지의 거리를 저장하는 d[]배열에서 최대값의 개수를 찾는다
"""
from math import inf
import heapq

def solution(n, edge):
    graph = [[False] * (n+1) for _ in range(n+1)]
    for e in edge:
        graph[e[0]][e[1]] = True
        graph[e[1]][e[0]] = True

    start = 1
    d = [inf]*(n+1)
    d[start] = 0
    # checked를 그냥 배열? 아니면 T/F배열? -> 그냥 배열로하는게 낫다
    not_checked = list(range(1,n+1))
    # checked = [False]*(n+1)
    # checked[0] = True

    while True:
        for i,v in enumerate(graph[start]):
            if v:
                if d[start] + 1 < d[i]: d[i] = d[start]+1
        not_checked.remove(start)
        next_list = [(d[i],i) for i in not_checked]
        # checked[start] = True
        # next_list = [(d[i],i) for i,v in enumerate(checked) if v == False]
        heapq.heapify(next_list)
        if not next_list: break
        start = heapq.heappop(next_list)[1]
        # print(start)


    return d.count(max(d[1:]))

print(solution(6,[[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]))