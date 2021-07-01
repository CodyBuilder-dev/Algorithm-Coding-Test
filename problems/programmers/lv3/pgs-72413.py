"""
제목 : 합승 택시 요금

아이디어 : 모든 경유지에 대해 최소요금을 계산한다
(1) 시간복잡도는 경유지 200가지 * 각 경유지별 최대거리 계산 3회 (200+200+200)
- 충분할 것 같다

(2) 최소요금 계산법은 다익스트라로 한다
- 다음지점까지의 거리가 지금보다 짧으면 진입 및 갱신, 아니면 미진입
"""
from collections import deque
from math import inf

def solution(n, s, a, b, fares):
    graph = dict.fromkeys(range(n+1))

    for k in graph:
        graph[k] = {}

    # graph = [[0] * (n + 1) for _ in range(n + 1)]
    for f in fares:
        graph[f[0]][f[1]] = f[2]
        graph[f[1]][f[0]] = f[2]


    # 모든 경유지에 대해 다익스트라계산
    q = deque()
    cost_from_s = [inf] * (n + 1)
    q.append(s)
    cost_from_s[s] = 0
    while q:
        now = q.popleft()
        for nxt in graph[now]:
            # for next,v in list(filter(lambda x: x[1] > 0,enumerate(graph[now]))):
            # if cost[next] >= cost[now] + graph[now][next]:
            if cost_from_s[nxt] >= cost_from_s[now] + graph[now][nxt]:
                q.append(nxt)
                cost_from_s[nxt] = cost_from_s[now] + graph[now][nxt]

    min_cost = inf
    for m in range(1,n+1):
        if cost_from_s[m] >= min_cost: continue

        cost_from_m = [inf] * (n + 1)
        q.append(m)
        cost_from_m[m] = 0
        while q:
            now = q.popleft()
            for nxt in graph[now]:
                # for next,v in list(filter(lambda x: x[1] > 0,enumerate(graph[now]))):
                # if cost[next] >= cost[now] + graph[now][next]:
                if cost_from_m[nxt] >= cost_from_m[now] + graph[now][nxt]:
                    q.append(nxt)
                    cost_from_m[nxt] = cost_from_m[now] + graph[now][nxt]

        temp = cost_from_s[m] + cost_from_m[a] + cost_from_m[b]
        min_cost = min(min_cost,temp)
    return min_cost

print(solution(6,	4,	6,	2,	[[4, 1, 10], [3, 5, 24], [5, 6, 2], [3, 1, 41], [5, 1, 24], [4, 6, 50], [2, 4, 66], [2, 3, 22], [1, 6, 25]]))
print(solution(7,	3,	4,	1,	[[5, 7, 9], [4, 6, 4], [3, 6, 1], [3, 2, 3], [2, 1, 6]]))
print(solution(6,	4,	5,	6,	[[2,6,6], [6,3,7], [4,6,7], [6,5,11], [2,5,12], [5,3,20], [2,4,8], [4,3,9]]))