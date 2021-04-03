"""
제목 : 하샤드 수

아이디어 : 그냥 구현하면 됨

구현 :
- 최대한 짧게 구현해보자
"""

def solution(x) :
    return True if x%sum([int(char) for char in str(x)])==0 else False

print(solution(10))
print(solution(12))
print(solution(11))
print(solution(13))