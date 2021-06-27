"""
제목 : [3차]방금그곡

아이디어 :
- #을 다른 알파벳으로 치환하면 굳이 정규식 안써도 된다
"""
from datetime import datetime
from math import inf


def sharp_to_others(m):
    stack = []
    mapping = {
        "C#": "Z", "D#": "Y", "F#": "X", "G#": "W", "A#": "V", "E#": "U"
    }

    for i, c in enumerate(m):
        if c == '#':
            origin = stack.pop() + c
            stack.append(mapping[origin])
        else:
            stack.append(c)
    return ''.join(stack)


def sharp_to_lower(s):
    s = s.replace('C#', 'c').replace('D#', 'd').replace('F#', 'f').replace('G#', 'g').replace('A#', 'a')
    return s


def parse_time(time):
    return int(time[:2]) * 60 + int(time[3:])


def find_sublist(m, music):
    for i in range(len(music) - len(m) + 1):
        if music[i:i + len(m)] == m:
            return True
    return False


def solution(m, musicinfos):
    # m = sharp_to_others(m)
    m = sharp_to_lower(m)

    # max_time = -987654321
    # max_idx = -987654321
    max_time = -inf
    max_idx = -inf
    for i, musicinfo in enumerate(musicinfos):
        musicinfo = musicinfo.split(',')

        # 시간 파싱
        # delta = datetime.strptime(musicinfo[1], "%H:%M") - datetime.strptime(musicinfo[0], "%H:%M")
        # duration = delta.seconds // 60
        duration = parse_time(musicinfo[1]) - parse_time(musicinfo[0])

        # 음계 파싱
        # musicinfo[3] = sharp_to_others(musicinfo[3])
        musicinfo[3] = sharp_to_lower(musicinfo[3])

        played_music = (duration // len(musicinfo[3]) + 1) * musicinfo[3]
        played_music = played_music[:duration]

        # if find_sublist(m,played_music):
        if m in played_music:
            if duration > max_time:
                max_time = duration
                max_idx = i

    # if max_idx != -987654321:
    if max_idx != -inf:
        return musicinfos[max_idx].split(',')[2]
    else:
        return "(None)"


# print(solution("ABCDEFG",["12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"]))
# print(solution("CC#BCC#BCC#BCC#B",["03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"]))
# print(solution("CC#BCC#BCC#BCC#B", ["03:00,03:05,FOO,CC#B"]))
print(solution("ABC",["12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"]))
print(solution("ABCDE#FG", ["12:00,12:14,HELLO,CDEFGAB","13:00,13:10,WORLD,ABCDE#FG"]))
