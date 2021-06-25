"""
제목 : 여행경로

아이디어 : 그래프 탐색
- ICN을 출발지로 해서 탐색하면 된다

구현 :
(1) dict를 이용한 그래프로 구현
- 각 공항은 다음으로 갈수 있는 공항들의 목록을 가진다
- 공항 목록을 알파벳순으로 정렬해 두면 무조건 알파벳 순으로 경로를 탐색한다
- 그래프는 tickets를 파싱하면서 초기화한다
    - 모든 공항을 방문할 수 있다 <- 모든 공항이 적어도 도착지에 1번은 나온다

(2) stack를 이용한 dfs 구현
- 매우 조잡하다...
"""
from collections import deque

def solution(tickets):
    graph = dict()
    for t in tickets:
        start,end = t
        if not graph.get(start): graph[start] = []
        graph[start].append(end)

    for k in graph:
        graph[k] = deque(sorted(graph[k], reverse=True))

    stack = ["ICN"]
    while stack:
        current = stack[-1]
        if graph.get(current):
            stack.append(graph[current].pop())
        else:
            if len(stack) == len(tickets)+1:
                return list(stack)
            else:
                while True:
                    last = stack.pop()
                    if graph[stack[-1]]:
                        graph[stack[-1]].appendleft(last)
                        break
                    else:
                        graph[stack[-1]].appendleft(last)






# print(solution([["ICN", "JFK"], ["HND", "IAD"], ["JFK", "HND"]]))
# print(solution([["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL","SFO"]]))
# print(solution([["ICN","ICN"]]))
# print(solution([["ICN","ACN"],["ACN","ICN"]]))
print(solution([["ICN","SCN"],["SCN","ICN"],["ICN","ACN"],["ACN","DCN"]]))