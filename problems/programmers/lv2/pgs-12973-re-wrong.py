"""
제목 : 짝지어 제거하기

아이디어 : 정규표현식 사용
-> 결과 : 시간초과 및 실패...
"""
import re

def solution(s):
    while True:
        matches = re.findall(r'((.)\2+)', s)
        if not matches: break
        result = [item[0] for item in matches]
        for res in result:
            s = s.replace(res,'')
    return 0 if s else 1

print(solution("baabaa"))
# matches = re.match(r'((.)\2+)', 'abbcdeee')
matches = re.findall(r'((.)\2+)', 'abbcdeee')
print(matches)
# result = [item[0] for item in matches]
# print(result)