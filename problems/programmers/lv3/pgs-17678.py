"""
제목 : [1차] 셔틀버스

아이디어 :
(1) 버스 출발시간을 dictionary의 key로, 탑승객 목록을 value로 집어넣는다

(2) 승객 리스트를 돌면서, 이 승객이 탈 수 있는 가장 빠른 버스를 이분탐색으로 찾는다
- 승객을 도착시간순으로 정렬한 후, 빠르게 온 승객부터 순차적으로 버스에 태운다고 하자
- 이분탐색으로 출발시간이 승객의 대기시간 이후인 버스 중 가장 가까운 버스를 찾는다(Upper Bound)
- 해당 버스의 탑승자 수가 m명 미만이면 승객을 집어넣고, m명 이상이면 다음 버스를 찾는다
    - 탈수있을때가지 반복한다


(3) 모든 버스와 승객 정보가 확인되면, 그냥 프로도를 제일 마지막 버스에 태운다
 - 제일 마지막 버스가 비어있으면, 제일 마지막 버스 출발시간에 와서 타면 된다
 - 제일 마지막 버스가 꽉 찼으면, 제일 마지막 사람에 타는 사람보다 1분 빨리 와서 타면 된다

구현 :
시간의 사칙연산이 필요하므로 datetime대신 timedelta를 쓰자!
"""
from datetime import datetime,timedelta
from bisect import bisect_left


def solution(n, t, m, timetable):
    term = timedelta(minutes=t)

    bus_schedule = {}
    for i in range(n):
        bus_schedule[timedelta(hours=9) + i*term] = []

    for person in sorted(timetable):
        dt = datetime.strptime(person, "%H:%M")
        td = timedelta(hours=dt.hour, minutes=dt.minute)

        # 탈수있는 가장 빠른 버스를 이분탐색으로 찾는다
        idx = bisect_left(list(bus_schedule.keys()),td)
        while idx < len(bus_schedule.keys()):
            bus = bus_schedule[list(bus_schedule.keys())[idx]]
            if len(bus) < m:
                bus.append(td)
                break
            idx+=1


    # 그냥 돌면 됨
    answer = ""
    last = list(bus_schedule.keys())[-1]
    if len(bus_schedule[last]) <m:
        answer = last
    else:
        answer = bus_schedule[last][-1]-timedelta(minutes=1)
    return "%02d:%02d" % (answer.seconds//3600,answer.seconds%3600//60)

print(solution(1,	1,	5,	["08:00", "08:01", "08:02", "08:03"]))
print(solution(2,	10,	2,	["09:10", "09:09", "08:00"]))
print(solution(2,	1,	2,	["09:00", "09:00", "09:00", "09:00"]))
print(solution(1,	1,	5,	["00:01", "00:01", "00:01", "00:01", "00:01"]))
print(solution(1,	1,	1,	["23:59"]))
print(solution(10,	60,	45,	["23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"]))