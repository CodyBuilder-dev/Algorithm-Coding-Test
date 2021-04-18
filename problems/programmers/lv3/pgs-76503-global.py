"""
제목 : 모두 0으로 만들기

아이디어 : DFS
(1) DFS를 이용해 가장 말단에서부터 출발한다
(2) 말단에서부터 말아올리며 총 이동횟수를 더한다
(3) 아무것도 없는 0인 노드에 대해서 수행해도, 횟수에 0만큼 추가되므로 상관없다
"""

import sys
sys.setrecursionlimit(1000000)

answer = 0

def dfs(node,a,adj,visited):
    global answer
    for next_node in adj[node]:
        if not visited[next_node]:
            visited[next_node]=True
            temp = dfs(next_node,a,adj,visited)
            a[node] += temp
            answer += abs(temp)

    return a[node]

def solution(a, edges):
    global answer
    if sum(a): return -1

    adj = [[] for i in range(len(a))]
    visited = [False]*len(a)

    for edge in edges:
        u,v = edge
        adj[u].append(v)
        adj[v].append(u)
    visited[0] = True
    dfs(0,a,adj,visited)
    return answer

# 테스트 케이스
print(solution([-5,0,2,1,2],[[0,1],[3,4],[2,3],[0,3]]))
print(solution([0,0,0,0,0],[[0,1],[3,4],[2,3],[0,3]]))
print(solution([0,1,0],[[0,1],[1,2]]),-1)
