"""
제목 : [1차] 추석 트래픽

아이디어 :
특정 구간에서 '처리 중'인 개수는 이렇게 판단한다
- 구간의 시작점보다 end가 같거나 크고
- 구간의 끝점보다는 start가 같거나 작아야 한다

구간을 어떻게 탐색할 것인가
- 모든 시작점 끝점을 다 추출한다
- 거기를 start로 해서 전체를 다 검사한다
    - 시작점,끝점은 최대 4000개, 요청은 최대 2000개이므로 800만개 선에서 해결

구현 :
(!) 시작점과 끝점을 ms단위로 변환해서 저장

(2) 저장한 시작점과 끝점을 start로 해서 구간을 탐색

구현 2 :
(1) 시작점과 끝점을 ms단위로 변환해서 저장

(2) 모든 구간을 다 탐색
0부터

"""

def parse_time(time):
    _, s, t = time.split()
    hh, mm, ss = s.split(':')

    ss, ms = ss.split('.')

    ms = int(ms)
    ss = 1000 * int(ss)
    mm = 60 * 1000 * int(mm)
    hh = 60 * 60 * 1000 * int(hh)
    s = hh + mm + ss + ms

    if '.' in t:
        ts, ms = t[:-1].split('.')

    else:
        ts, ms = t[:-1], '0'

    ms = int((ms + ('0' * 3))[:3])
    ts = 1000 * int(ts)

    t = ts + ms
    return s, t


def solution(lines):
    boundaries = []
    parsed_lines = []
    # time_cnt = [0]*86_400_000

    for line in lines:
        e, t = parse_time(line)
        s = e - t +1
        boundaries.append(s)
        boundaries.append(e)
        parsed_lines.append((s, e))


    boundaries = sorted(boundaries)
    parsed_lines = sorted(parsed_lines, key=lambda x: x[0])

    max_cnt = -987654321
    # for i in range(boundaries[0],boundaries[-1]):
        # boundary = i
    for boundary in boundaries:
        boundary_end = boundary + 999

        temp = 0
        for parsed_line in parsed_lines:
            if parsed_line[0] <= boundary and parsed_line[1] >= boundary:
                temp += 1
            elif parsed_line[0] >= boundary and parsed_line[1] <= boundary_end:
                temp += 1
            elif parsed_line[0] <= boundary_end and parsed_line[1] >= boundary_end:
                temp += 1


        max_cnt = max(temp, max_cnt)
    return max_cnt
#
print(solution([
"2016-09-15 01:00:04.001 2.0s",
"2016-09-15 01:00:07.000 2s"
]),1)
# print(solution([
# "2016-09-15 01:00:04.002 2.0s",
# "2016-09-15 01:00:07.000 2s"
# ]),2)
print(solution([
"2016-09-15 20:59:57.421 0.351s",
"2016-09-15 20:59:58.233 1.181s",
"2016-09-15 20:59:58.299 0.8s",
"2016-09-15 20:59:58.688 1.041s",
"2016-09-15 20:59:59.591 1.412s",
"2016-09-15 21:00:00.464 1.466s",
"2016-09-15 21:00:00.741 1.581s",
"2016-09-15 21:00:00.748 2.31s",
"2016-09-15 21:00:00.966 0.381s",
"2016-09-15 21:00:02.066 2.62s"
]),7)