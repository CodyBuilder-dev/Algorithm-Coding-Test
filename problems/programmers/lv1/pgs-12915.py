"""
제목 : 문자열 내 마음대로 정렬하기

아이디어 : 맨 앞에 해당 문자를 붙힌 후 정렬
"""

def solution(strings, n):
    new_strings = [string[n] + string for string in strings ]
    return [string[1:] for string in  sorted(new_strings)]

strings = ["sun", "bed", "car"]
n = 1
print(solution(strings,n))
