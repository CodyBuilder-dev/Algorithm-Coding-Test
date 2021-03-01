"""
제목 :  문자열 내림차순으로 배치하기


아이디어 : 아스키 코드로 나타내면
z > a, a > Z , Z > A
"""

def solution(s) :
    return ''.join(sorted(s, key = lambda c:-ord(c)))

s= "Zbcdefg"
print(solution(s))
