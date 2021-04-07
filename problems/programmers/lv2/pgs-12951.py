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
    s = re.sub(r'\b[a-z]',lambda x : x.group().upper(), s)
    s = re.sub(r'\B[A-Z]',lambda x : x.group().lower(), s)
    return s

print(solution("3people unFollowed me"))
print(solution("for the last week"))