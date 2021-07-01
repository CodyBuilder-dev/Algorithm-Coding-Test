"""
제목 : 호텔 방 배정

아이디어 : 이거 이분탐색 아닌가?
- 시간복잡도 : 2*10^5 * log(10^12)
- 공간복잡도 : 근데 미리 booked를 구현하면 10^12
    - 따라서 그냥 그때그떄 answer에 집어넣는 식으로 해야 함

- 현재 수 N보다 같거나 큰것 중에 제일 작은거 판정(UPPER BOWND)
    - 없다? = N이 비었다 = N추가
    - N이다? = N이 찼다- > N+1를 현재 수로 생각
    - N+1이상이다? = N이 안찼다 -> N 집어넣기

-> 느린 이유 : 매번 sort를 해야 함
"""
from bisect import *

def solution(k, room_number):
    answer = []
    for n in room_number:
        if not answer:
            answer.append(n)
            continue
        temp = n
        while True:
            i = bisect_left(sorted(answer),temp)

            if i == len(answer):
                answer.append(temp)
                break
            elif sorted(answer)[i] == temp:
                temp += 1
            elif sorted(answer)[i] > temp:
                answer.append(temp)
                break
    return answer

print(solution(10,	[1,3,4,1,3,1]))