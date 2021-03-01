"""
제목 : 문자열 내 마음대로 정렬하기

아이디어 : 
"""

def solution(strings, n):
    return sorted(strings, key = lambda string : (string[n],string))

strings = ["sun", "bed", "car"]
n = 1
print(solution(strings,n))
