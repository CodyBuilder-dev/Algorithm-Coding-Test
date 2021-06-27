"""
제목 : [3차]방금그곡

아이디어 :
(1) 음악의 전체를 만든다
- 재생시간 파싱
    - 시작시간, 종료시간은 datetime.strptime으로 파싱 가능
    - 재생시간은 timedelta로 처리

- 음악 음계 파싱
    - CC#B일 때 이를 어떻게 자를 것인가? re사용
    - r'\w#?'

- 재생횟수만큼 반복한 뒤 앞에서부터 총길이만큼 자르기

(2) 일치여부를 검사한다
- 우선 음악 정보가 담긴 배열을 정렬한다
    - 총 재생시간 순으로 내림차순 정렬,
    - 인덱스 순으로 오름차순 정렬한다

- 부분문자열 일치여부를 검색한다
    in등의 키워드를 사용
        - 단, ABC와 ABC#을 다르게 취급해야 하므로 문자열이 아닌 리스트에서 검사
    - 그냥 앞에서부터 순차적으로 일치판정 수행
"""

from datetime import datetime
from math import ceil
import re

def find_sublist(m,music):
    for i in range(len(music)-len(m)+1):
        if music[i:i+len(m)] == m:
            return True
    return False

def solution(m, musicinfos):
    m = re.findall(r'\w#?',m)

    new_infos= []
    for i,musicinfo in enumerate(musicinfos):
        # 시간 파싱
        musicinfo = musicinfo.split(',')
        delta = datetime.strptime(musicinfo[1],"%H:%M") - datetime.strptime(musicinfo[0],"%H:%M")
        duration = delta.seconds//60

        # 음계 파싱
        musicinfo[3] = re.findall(r'\w#?',musicinfo[3])
        period = len(musicinfo[3])

        played_music = (musicinfo[3]*ceil(duration/period))[:duration]

        # 인덱스, 재생시간, 이름, 악보
        new_infos.append([i,duration,musicinfo[2],played_music])

    new_infos = sorted(new_infos,key=lambda x:(-x[1],x[0]))
    for new_music in new_infos:
        if find_sublist(m,new_music[3]):
            return new_music[2]
    return "(None)"

# print(solution("ABCDEFG",["12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"]))
# print(solution("CC#BCC#BCC#BCC#B",["03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"]))
print(solution("CC#BCC#BCC#BCC#B",["03:00,03:05,FOO,CC#B"]))