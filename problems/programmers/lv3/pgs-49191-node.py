"""
제목 : 순위

요구조건 : 정확히 순위를 매길 수 있는 사람의 수
- 정확한 순위란? N명 중에 본인이 몇위인지 정확히 판단이 되는 것

아이디어 : 정확한 순위를 아는 방법
(1) 내 앞에 몇 명이 있는지, 내 뒤에 몇 명이 있는지 모든 정보가 있다.
(2) 정보가 부족하다면, 적어도 자신에게 승/패한 상대를 따라갔을 때 모든 정보가 획득 가능하다

구현 :그래프를 이용해 탐색
- dict로 그래프를 구현한다
    - 각 노드는 자기를 이긴사람, 자기에게 진사람를 저장한다
- 모든 점을 출발점을 잡아 그래프를 탐색한다
    - 위로 올라가면서 upper를 체크한다
    - 아래로 내려가면서 lower를 체크한다
    - 이때 내려가거나 올라가는건 queue를 사용하면 될 듯?
    - 더 갈수 없을때까지 간후 upper와 lower를 합쳤을때 모든정보가 있으면 된다

반례 주의 :

"""
from collections import deque

def solution(n, results):
    graph = dict.fromkeys(range(1, n + 1))
    for k in graph:
        graph[k] = {"up": set(), "down": set()}

    for r in results:
        win, lose = r
        graph[lose]["up"].add(win)
        graph[win]["down"].add(lose)


    answer = 0
    for k in graph:
        checked = [False] * (n + 1)
        checked[k] = True

        q = deque(graph[k]["up"])
        while q:
            now = q.popleft()

            if not checked[now]:
                checked[now] = True
                q.extend(graph[now]["up"])

        q = deque(graph[k]["down"])
        while q:
            now = q.popleft()

            if not checked[now]:
                checked[now] = True
                q.extend(graph[now]["down"])

        if sum(checked[1:]) == n: answer += 1
    return answer

# print(solution(100,[[1,2]]))
# print(solution(0,[]))
# print(solution(1, [[1,1]]))
# print(solution(3, [[1,2],[2,3],[3,1]]))
# print(solution(5,	[[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]]))
# print(solution(4, [[1,2],[2,3],[1,4]]))
print(solution(5, [[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]]), 2)
print(solution(7, [[4, 3], [4, 2], [3, 2], [1, 2], [2, 5], [5,6], [6,7]]), 4)
print(solution(6, [[1,2], [2,3], [3,4], [4,5], [5,6]]), 6)
print(solution(5, [[1, 4], [4, 2], [2, 5], [5, 3]]), 5)
print(solution(5, [[3, 5], [4, 2], [4, 5], [5, 1], [5, 2]]), 1)
print(solution(3, [[1,2],[1,3]]), 1)
print(solution(6, [[1,6],[2,6],[3,6],[4,6]]), 0)
print(solution(8, [[1,2],[3,4],[5,6],[7,8]]),0)
print(solution(9, [[1,2],[1,3],[1,4],[1,5],[6,1],[7,1],[8,1],[9,1]]), 1)
print(solution(6, [[1,2],[2,3],[3,4],[4,5],[5,6],[2,4],[2,6]]), 6)
print(solution(4, [[4,3],[4,2],[3,2],[3,1],[4,1], [2,1]]), 4)
print(solution(3,[[3,2],[3,1]]), 1)
print(solution(4, [[1,2],[1,3],[3,4]]), 1)
print(solution(5, [[1, 4], [4, 2], [2, 5], [5, 3]]),5)