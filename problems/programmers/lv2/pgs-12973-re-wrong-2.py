"""
제목 : 짝지어 제거하기

아이디어 : 정규표현식 사용
-> 결과 : 시간초과 및 실패...
"""
import re

def solution(s):
    while True:
        matches = re.search(r'((.)\2)',s)
        if not matches: break
        s = re.sub(r'((.)\2)','', s)

    return 0 if s else 1

print(solution("baabaa"))
# matches = re.match(r'((.)\2+)', 'abbcdeee')
# matches = re.findall(r'((.)\2+)', 'abbcdeee')

# result = [item[0] for item in matches]
# print(result)
# x = "aacaab"
# a = re.sub(r'((.)\2)','',x)
# print(re.sub(r'((.)\2)','',x))
# print("a:",a)
# print("x:",x)