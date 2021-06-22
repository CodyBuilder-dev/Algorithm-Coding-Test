"""
제목 : 섬 연결하기

아이디어 : 최소 스패닝 트리의 정의를 그대로 옮겨둔 듯한 문제

구현 :
(1) 그래프를 구현한다
- 크루스칼을 쓸거면, 최소길이 간선의 길이를 빨리 찾는게 중요하므로, 간선에 대한 우선순위 큐를 만든다
- (간선 길이, 출발지, 도착지)
(2) 크루스칼 알고리즘을 쓴다
- 모든 점을 방문했는지 체크한다
- 간선을 뽑는다
- 유니온-파인드로 검사한다
- 사이클이 아니면 추가한다
"""
from queue import PriorityQueue


def find(parents, child):
    if child == parents[child]:
        return child

    return find(parents, parents[child])

def union(parents, left, right):
    left_parent = find(parents,left)
    right_parent = find(parents,right)
    parents[right_parent] = left_parent

    # 전체 갱신
    for i in range(len(parents)):
        parents[i] = find(parents,i)

    return parents



def solution(n, costs):
    pq = PriorityQueue()
    for cost in costs:
        pq.put([cost[-1]] + cost[:-1])

    visited = [False]*n
    parents = list(range(n))

    answer =0
    while not pq.empty():
        cost , start, end = pq.get()
        # 사이클 미발생시, 즉 start와 end의 집합이 다를 시
        if find(parents, start) != find(parents, end):
            answer += cost
            parents = union(parents,start,end)

    return answer

print(solution(4,	[[0,1,1],[0,2,2],[1,2,5],[1,3,1],[2,3,8]]))