"""
제목 : 호텔 방 배정

아이디어 : 이거 heap으로 구현하지 않나
- 왼쪽힙 오른쪽힙 2개 만든다
- 왼쪽힙의 최소랑 비교한다
    - 왼쪽힙보다
- 오른쪽힙의 최소를 찾는다
    - N보다 작으면 왼쪽힙에 넘김
    - N이면 왼쪽으로 넘기고 N+1로 생각
    - N보다 크다? 오른쪽 힙에 합치고 다시 왼쪽힙에 있던것들 오른쪽 힙으로 합침


5 [] [1 2 5 8]
5 [1] [2 5 8]
5 [1 2] [5 8]
6 [1 2 5] [8]
[1 2 5] [6 8]

5 [] [1 2 8]
5 [1] [2 8]
5 [1 2] [8]
[1 2] [5 8]

-> 느린 이유 : 매번 array를 append해야 함
"""
from heapq import *

def solution(k, room_number):
    left = []
    right = []

    for i,n in enumerate(room_number):
        if not right:
            heappush(right,(n,i))
            continue

        temp = n
        while right:
            head = heappop(right)
            if head[0] < temp:
                left.append(head)
            elif head[0] == temp:
                temp += 1
                left.append(head)
            else:
                heappush(right,(temp,i))
                heappush(right, head)
                for j in left:
                    heappush(right, j)
                left = []
                break

        if not right:
            heappush(right,(temp,i))
            for j in left:
                heappush(right, j)
            left = []

    answer = [0] * len(room_number)
    for r in right:
        answer[r[1]] = r[0]

    return answer

print(solution(10,	[1,3,4,1,3,1]))