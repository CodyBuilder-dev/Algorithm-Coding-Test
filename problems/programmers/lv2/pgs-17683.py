"""
제목 : 방금 그곡

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
    for i,music in enumerate(musicinfos):
        # 시간 파싱
        music = music.split(',')
        delta = datetime.strptime(music[1],"%H:%M") - datetime.strptime(music[0],"%H:%M")
        duration = delta.seconds//60 
        # print(delta.seconds//60)
        
        # 음악 파싱
        music[3] = re.findall(r'\w#?',music[3])
        # print(music[3])
        period = len(music[3])

        played_music = (music[3]*ceil(duration/period))[:duration]
        # print(played_music)
        new_infos.append([played_music,music[2],duration,i])


    # print(musicinfos)  # for문 내에서 변하지 않음
    new_infos = sorted(new_infos,key=lambda x:(-x[2],x[3]))
    for music in new_infos:
        if find_sublist(m,music[0]):
            return music[1]
    return "(None)"

print(solution("ABCDEFG",["12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"]))
print(solution("CC#BCC#BCC#BCC#B",["03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"]))