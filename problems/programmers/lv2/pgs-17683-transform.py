"""
제목 : [3차]방금그곡

아이디어 :
- #을 다른 알파벳으로 치환하면 굳이 정규식 안써도 된다
"""

from datetime import datetime


def transform(m):
    stack = []
    mapping = {
        "C#": "Z",
        "D#": "Y",
        "F#": "X",
        "G#": "W",
        "A#": "V",
        "E#": "U"
    }

    for i, c in enumerate(m):
        if c == '#':
            origin = stack.pop() + c
            stack.append(mapping[origin])
        else:
            stack.append(c)
    return ''.join(stack)


def find_sublist(m, music):
    for i in range(len(music) - len(m) + 1):
        if music[i:i + len(m)] == m:
            return True
    return False


def solution(m, musicinfos):
    m = transform(m)

    new_infos = []
    for i, musicinfo in enumerate(musicinfos):
        # 시간 파싱
        musicinfo = musicinfo.split(',')
        delta = datetime.strptime(musicinfo[1], "%H:%M") - datetime.strptime(musicinfo[0], "%H:%M")
        duration = delta.seconds // 60

        # 음계 파싱
        musicinfo[3] = transform(musicinfo[3])

        played_music = (duration//len(musicinfo[3]))*musicinfo[3]
        played_music = played_music[:duration]

        # 인덱스, 재생시간, 이름, 악보
        new_infos.append([i, duration, musicinfo[2], played_music])

    new_infos = sorted(new_infos, key=lambda x: (-x[1], x[0]))
    for new_music in new_infos:
        if find_sublist(m, new_music[3]):
            return new_music[2]
    return "(None)"


print(solution("ABCDEFG",["12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"]))
print(solution("CC#BCC#BCC#BCC#B",["03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"]))
print(solution("CC#BCC#BCC#BCC#B", ["03:00,03:05,FOO,CC#B"]))
print(solution("ABCDE#FG", ["12:00,12:14,HELLO,CDEFGAB","13:00,13:10,WORLD,ABCDE#FG"]))
