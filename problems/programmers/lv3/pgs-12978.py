"""
제목 : 배달

아이디어 : 결국, 출발점으로부터 모든 다른 점까지의 최단거리 완전 탐색
(1) 출발점에서 한 도착점까지 최단거리 구하기
-
(2) 모든 도착점에 대해 반복하기

아이디어 : 아니면 그냥 BFS를 돌면서, 최소가 될때마다 갱신?
- '경주로 건설' 문제의 쉬운맛 버전인듯
"""
from math import inf
from collections import deque


def solution(N, road, K):
    graph = [[inf]*(N+1) for _ in range(N+1)]
    cost = [[inf]*(N+1) for __ in range(N+1)]
    for r in road:
        s,e,v = r
        if v < graph[s][e]:
            graph[s][e],graph[e][s] = v,v
            cost[s][e], cost[e][s] =v,v

    for i in range(1,N+1):
        cost[i][i] = 0

    dq = deque([1])
    while dq:
        current = dq.popleft()
        for i,next in enumerate(graph[current]):
            if next != inf: #연결되어 있는 경우
                if cost[1][current] + cost[current][i] <= cost[1][i]:
                    cost[1][i] = cost[1][current] + cost[current][i]
                    dq.append(i)

    return len(list(filter(lambda x:x<=K,cost[1])))


    # return graph

print(solution(5,[[1,2,1],[2,3,3],[5,2,2],[1,4,2],[5,3,1],[5,4,2]],3))

