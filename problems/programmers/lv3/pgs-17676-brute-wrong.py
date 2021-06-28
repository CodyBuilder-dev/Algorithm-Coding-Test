"""
제목 : [1차] 추석 트래픽

아이디어 :
- 전체 시간의 배열을 구현
- 각 트래픽 구간을 더한다
- 이후 전체를 탐색하면서 최대 구간을 찾는다
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

    # 오차없이 하고 싶으면 아래처럼 파싱 및 int를 이용해 처리하는게 좋다
    # if '.' in t:
    #     ts, ms = t[:-1].split('.')
    #
    # else:
    #     ts, ms = t[:-1], '0'
    #
    # ms = int((ms + ('0' * 3))[:3])
    # ts = 1000 * int(ts)
    #
    # t = ts + ms

    # 그러나 이 문제에서는, 실수의 소수점 자리수가 무조건 고정이므로 float을 써도 정답처리가 된다
    t = int(float(t[:-1]))*1000
    return s, t


def solution(lines):
    boundaries = []
    # parsed_lines = []
    time_cnt = [0]*86_400_000

    for line in lines:
        e, t = parse_time(line)
        s = e - t +1
        boundaries.append(s)
        boundaries.append(e)
        time_cnt[s] += 1
        if e < len(time_cnt):
            time_cnt[e+1] -= 1

    for i in range(1,len(time_cnt)):
        time_cnt[i] += time_cnt[i - 1]
    for i in range(1, len(time_cnt)):
        time_cnt[i] += time_cnt[i - 1]
    boundaries = sorted(boundaries)


    max_cnt = -987654321
    for boundary in boundaries:
        boundary_end = boundary + 999

        temp = time_cnt[boundary_end] - time_cnt[boundary]
        max_cnt = max(temp, max_cnt)
    return max_cnt
#
# print(solution([
# "2016-09-15 01:00:04.001 2.0s",
# "2016-09-15 01:00:07.000 2s"
# ]),1)
print(solution([
"2016-09-15 01:00:04.002 2.0s",
"2016-09-15 01:00:07.000 2s"
]),2)
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