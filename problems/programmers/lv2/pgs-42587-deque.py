"""
접근법 : 예측 X, 구현
1. for 돌림
2. 있으면 맨 뒤로, 없으면 출력
3. 무한반복
"""

from collections import deque

def solution(priorities, location):
    answer = 1
    prioritiesWithMark = [(v,1) if i == location else (v,-1) for i,v in enumerate(priorities)]
    dq = deque(prioritiesWithMark)

    while len(dq) > 0 :
        a = dq.popleft()
        
        if len(dq) == 0 : break
        
        if a[0] >= max([b[0] for b in dq]) : 
            if a[1] == 1 : break
            else : answer += 1
        else : dq.append(a)
        
    return answer

priorities = [2, 1, 3, 2]
location = 2

priorities = [1, 1, 9, 1, 1, 1]
location = 0

priorities = [1]
location= 0
print(solution(priorities, location))