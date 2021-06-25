"""
제목 : 광고 삽입

아이디어 : 시간을 key로 갖는 dict를 이용한다?
- 구간정보 저장이 어려움

아이디어 : 1초를 1칸으로 갖는 배열을 이용한다
(1) 구간정보 저장
- 구간을 초로 변환한다.
    - 99시간 등의 데이터가 존재하므로 datetime을 쓸수 없음
    - 시간, 분, 초를 파싱해 더한다
- 해당 구간의 모든 원소를 +1한다

(2) 최적구간 탐색
- 어차피 1초단위로 탐색해도 99*60*60 = 356400뿐이다
    - 모든 광고 구간의 경우에 수에 대해서 탐색해봐도 될듯

구현시 주의점 :
- 시청시간이 0초~10초면, 0부터 10초까지 모두 시청한다
- 광고의 길이가 x초라는 것은, 실제 구간의 길이는 0과 x를 포함하므로 x+1이다
"""
def parse_time(time):
    hh = int(time[:2])
    mm = int(time[3:5])
    ss = int(time[6:])
    return 3600*hh + 60*mm + ss

def solution(play_time, adv_time, logs):
    play_time = parse_time(play_time)
    adv_time = parse_time(adv_time)
    view_cnt = [0] * (play_time + 1)

    for log in sorted(logs):
        start,end = map(lambda x:parse_time(x), log.split('-'))

        view_cnt[start] += 1
        view_cnt[end] -= 1

    for i in range(1,play_time+1):
        view_cnt[i] += view_cnt[i-1]
    for i in range(1,play_time+1):
        view_cnt[i] += view_cnt[i-1]

    gugan_start_idx = 0
    gugan_end_idx = gugan_start_idx + adv_time
    gugan_cnt = view_cnt[gugan_end_idx-1]

    for i in range(0, play_time - adv_time+1):
        temp_gugan = view_cnt[i+adv_time] - view_cnt[i]
        if gugan_cnt < temp_gugan:
            gugan_start_idx = i + 1
            gugan_cnt = temp_gugan

    t, seconds = gugan_start_idx // 60, gugan_start_idx % 60
    hour, minute = t // 60, t % 60
    return f"{hour:02d}:{(minute) % 60:02d}:{seconds:02d}"


# print(solution("02:03:55",	"00:14:15",	["01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"]))
# print(solution("99:59:59",	"25:00:00",	["69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00"]))
# print(solution("50:00:00",	"50:00:00",	["15:36:51-38:21:49", "10:14:18-15:36:51", "38:21:49-42:51:45"]))
# print(solution("50:00:00",	"49:59:59",	["15:36:51-38:21:49", "10:14:18-15:36:51", "38:21:49-42:51:45"]))
print(solution("00:00:04", "00:00:01", ["00:00:01-00:00:02","00:00:00-00:00:02","00:00:00-00:00:01","00:00:00-00:00:01"]))