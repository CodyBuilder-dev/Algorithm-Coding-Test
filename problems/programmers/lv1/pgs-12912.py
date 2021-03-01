"""
제목 : 두 정수 사이의 합
"""

def solution(a, b):
    if a <= b : return sum(range(a,b+1))
    else : return sum(range(b,a+1))