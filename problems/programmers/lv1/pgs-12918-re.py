"""
제목 : 문자열 다루기 기본
"""
import re

def solution(s):
    if len(s) != 4 and len(s) != 6 :
        return False
    if re.findall('[A-z]',s) : return False
    else : return True

s = "123645"
#print(re.findall('[a-zA-Z]',s))
print(solution(s))

