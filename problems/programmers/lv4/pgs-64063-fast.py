"""
제목 : 호텔 방 배정

아이디어 : dict에 갈수 있는 가장 가까운 방의 정보를 저장한다
- dict의 key에 방번호가 없으면 그냥 넣고, value는 방번호 +1로 한다
- dict의 key에 방번호가 있으면, 해당 방번호의 value를 따라 반복적으로 탐색한다
    - 방번호가 없을 때까지 탐색한후 key와 value를 등록한다
    - 그전까지 탐색했던 모든 방의 value도 key+1로 갱신해준다
"""


def solution(k, room_number):
    answer = {}
    for n in room_number:
        if n not in answer:
            answer[n] = n+1
            continue
        temp = n
        templist = []
        while temp in answer:
            temp = answer[temp]
            templist.append(temp)

        answer[temp] = temp + 1
        for t in [n]+templist:
            answer[t] = temp+1

    return list(answer.keys())

print(solution(10,	[1,3,4,1,3,1]))