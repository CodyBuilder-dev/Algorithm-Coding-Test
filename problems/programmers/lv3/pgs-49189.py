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
    graph = dict.fromkeys(range(1,n+1))
    for e in edge:
        if graph[e[0]]: graph[e[0]][e[1]] = 1
        else: graph[e[0]] = {e[1]:1}

        if graph[e[1]]: graph[e[1]][e[0]] = 1
        else: graph[e[1]] = {e[0]:1}

    d = dict.fromkeys(range(1,n+1),inf)
    d[1] = 0

    q = []
    heapq.heappush(q,[d[1],1])


    while q:
        current_d, current_i = heapq.heappop(q)

        for next_i,next_d in graph[current_i].items():
            if current_d + next_d < d[next_i]:
                d[next_i] = current_d + next_d
                heapq.heappush(q,[d[next_i],next_i])
    return sum([1 for i,v in d.items() if v == max(d.values())])


print(solution(6,[[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]))