"""
제목 : 호텔 방 배정

아이디어 : 당연히 완탐은 안된다
- 2*10^5 * 10^12
- 하지만 정확성을 위해서라면 해볼만 함
"""

def solution(k, room_number):
    answer = {}
    for n in room_number:
        k = n
        while k in answer:
            k += 1
        answer[k] = True
    return list(answer.keys())

print(solution(10,	[1,3,4,1,3,1]))