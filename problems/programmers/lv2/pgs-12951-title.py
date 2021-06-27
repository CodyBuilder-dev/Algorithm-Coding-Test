"""
제목 : JadenCase 문자열 만들기

아이디어 : 정규표현식 사용?
- 단어 첫부분의 소문자를 찾는다
- 해당 부분을 대문자로 치환한다
- 문자열 가운데이 있는 대문자를 찾는다
- 해당 부분을 소문자로 치환한다
"""

import re

def solution(s):
    digit ="1234567890"
    s = re.findall(r'\w+\s*',s)
    return ''.join([w.title() if w[0] not in digit else w.lower() for w in s])

print(solution("3people unFollowed me"))
print(solution("for the last week"))