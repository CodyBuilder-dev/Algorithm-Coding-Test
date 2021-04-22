"""
아이디어 : DFS 혹은 BFS
- 점들을 순회하면서 더이상 순회할 수 없을 떄까지 순회후 네트워크의 개수 +1
- 이를 반복하면, 연결되지 않은 네트워크의 개수를 찾을 수 있다

구현: 인접 배열을 탐색
- 1번 점부터 하나씩 검사
- 해당 점이 1로 되어 있으면 순회 시작
    - 처음 시작하는 점을 큐에 삽입
    - 해당 큐에 연결된 점들 찾기
    - 연결된 점이 있으면 그점을 큐에 넣고, 인접배열의 연결정보를 0으로 처리(연결 끊기)
    - 더이상 진행할 수 없으면 count +1
"""
from collections import deque


def solution(n, computers):
    dq = deque()

    count = 0
    for i in range(len(computers)):
        if computers[i][i]:
            dq.append(i)
            computers[i][i] = 0
            while dq:
                current = dq.popleft()
                for idx, next in enumerate(computers[current]):
                    if next:
                        computers[current][idx] = 0
                        computers[idx][idx] = 0
                        computers[idx][current] = 0
                        dq.append(idx)
            count += 1
    return count