"""
제목 : 트리 트리오 중간값

아이디어 : 완탐
- Combination(250000,3) -> 불가능

아이디어 : 문제 해석
(1) 일단 제일 큰 값을 만든느 방법부터 확인
- 최소값, 최대값을 제외한 것중 제일 큰 값

(2) 루트를 기준으로 생각해보자
- 루트를 어디로 할 것인가?
    - 트리는 사실 아무데나 루트로 해도 된다
- 루트에서 리프까지의 거리는 BFS로 측정 가능
- 리프에서 리프간 거리도 알 수 있다
    - 루트가 공통조상인 경우는 리프거리 + 리프거리
    - 루트가 공통조상이 아닌 경우는 리프거리 + 리프거리
- 루트가 공통조상인 놈들간의 거리 중에 최대를 구한다

아이디어 : 트리의 지름
- 지름이 1개면 지름-1
- 지름이 2개면 지름
"""
from collections import deque

def solution(n, edges):
    answer = 0
    tree = dict.fromkeys(range(n))
    for k in tree:
        tree[k] = []


    for edge in edges:
        tree[edge[0] - 1].append(edge[1] - 1)
        tree[edge[1] - 1].append(edge[0] - 1)

    # 임의의 정점 루트로부터 거리 계산
    diameter = -987654321
    root = 0
    q = deque()
    distance = [0] * n
    visited = [False] * n
    visited[0] = True

    q.append([root,0])
    while q:
        now,now_d = q.popleft()
        for next in tree[now]:
            if not visited[next]:
                distance[next] = now_d+1
                visited[next] = True
                q.append([next,now_d+1])

    max_case = []
    # 가장 먼 친구들만 골라서 다시 먼 거리 계산
    # 가장 먼 친구 '하나만' 골라서 다시 먼 거리 계산
    # 가장 먼 친구 '두개만' 골라서 다시 먼 거리 계산
    max_distance = max(distance)
    starts = []
    for i in range(len(distance)):
        if distance[i] == max_distance:
            starts.append(i)
        if len(starts) > 1: break

    for i in starts:
        q2 = deque()
        distance2 = [0] * n
        visited2 = [False] * n
        visited2[i] = True

        q2.append([i, 0])
        while q2:
            now, now_d = q2.popleft()
            for next in tree[now]:
                if not visited2[next]:
                    distance2[next] = now_d + 1
                    visited2[next] = True
                    q2.append([next, now_d + 1])
        # print(i, distance2)
        max_distance2 = max(distance2)
        for j,d2 in enumerate(distance2):
            if d2 == max_distance2:
                max_case.append((i,j))

    if len(max_case) >1:
        return max_distance2
    else:
        return max_distance2 -1







print(solution(4,	[[1,2],[2,3],[3,4]]))
print(solution(5,	[[1,5],[2,5],[3,5],[4,5]]))