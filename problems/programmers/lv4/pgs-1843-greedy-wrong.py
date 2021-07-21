"""
제목 : 사칙연산

아이디어 : 그리디
- 어차피 플러스 순서는 상관없다
- 마이너스, 그 중에 앞에 것이 가장 큰걸 먼저 처리하는게 맞다
-> 틀림

아이디어 : 마이너스간의 최대화
- 앞에서부터 마이너스사이를 다 더한다
- 뒤에서부터 처리한다
"""
from collections import deque


def solution(arr):
    stack = []
    temp = 0
    for i in range(len(arr)):

        if arr[i].isdigit():
            temp += int(arr[i])
        if arr[i] == "-":
            stack.append(temp)
            temp = 0
            stack.append("-")
    stack.append(int(arr[-1]))

    dq = deque()
    while stack:
        now = stack.pop()
        if now == "-":
            front = stack.pop()
            back = dq.popleft()
            stack.append(front-back)
        else:
            dq.appendleft(now)
    return dq.pop()



print(solution(["1", "-", "3", "+", "5", "-", "8"]))
print(solution(["1", "-", "3", "+", "5", "-", "8", "-", "7"]),1)
print(solution(["5", "-", "3", "+", "1", "+", "2", "-", "4"]))
print(solution(["10","-","5","+","7","-","100"]))
print(solution(["5","+","999","-","1000","-","5"]))
print(solution(["5","-","999","-","1000","-","5"]),7)