"""
제목 : [1차] 셔틀버스

아이디어 : 다양한 접근법이 있을듯
(1) 버스 도착시간을 시뮬레이션 한다
- 앞에서부터 버스를 채워 나간다
- 가장 마지막

(3) 이분탐색을 한다
- 09:00부터 마지막 버스 신까지 본다
- 특정 x분에 줄을 섰을떄 탈수있을지 본다
    - 탈수있는지 판단은, 제일 가까운 다음 버스부터 탈수있을때까지 검사한다
    - 남아있는사람이 버스 승객보다 같거나 작아야 하고, 크면 다음버스를 기달야 한다
    - 못 탄 채로 다음 버스가 없으면 못탄다
    - 탈수있으면 뒤로 간다
    - 못타면 앞으로 간다

구현 :
시간의 사칙연산이 필요하므로 datetime대신 timedelta를 쓰자!
"""
from datetime import datetime,timedelta
from bisect import bisect_left



# print(datetime.strptime("09:00","%H:%M") datetime.strptime("10:00","%H:%M"))
def solution(n, t, m, timetable):
    term = timedelta(minutes=t)

    bus_schedule = {}
    for i in range(n):
        bus_schedule[timedelta(hours=9) + i*term] = []

    for person in sorted(timetable):
        dt = datetime.strptime(person, "%H:%M")
        td = timedelta(hours=dt.hour, minutes=dt.minute)

        # 가장 빠른 버스를 이분탐색으로?
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