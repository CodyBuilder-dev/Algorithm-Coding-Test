from collections import deque

def solution(scovile,K):
    dq = deque()
    scovile = deque(sorted(scovile))

    cnt = 0
    while len(scovile) + len(dq) >= 1:
        if len(dq) == 0 :
            smallest = scovile.popleft()
        elif len(scovile) ==  0 :
            smallest = dq.popleft()
        elif dq[0] > scovile[0]:
            smallest = scovile.popleft()
        else :
            smallest = dq.popleft()

        if smallest >= K : return cnt
        if len(dq) + len(scovile) ==0 : return -1

        if len(dq) == 0 :
            second = scovile.popleft()
        elif len(scovile) ==  0 :
            second = dq.popleft()
        elif dq[0] > scovile[0]:
            second = scovile.popleft()
        else :
            second = dq.popleft()

        dq.append(smallest+second*2)
        cnt += 1

    return cnt

scovile = [1, 2, 3, 9, 10, 12]
K = 7
print(solution(scovile,K))