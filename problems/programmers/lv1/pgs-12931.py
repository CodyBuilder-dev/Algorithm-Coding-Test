"""
제목 : 자연수 더하기

아이디어 : 그냥 자리수 더하면 됨('하샤드 수'문제 풀이와 동일)
"""
def solution(n):
    return sum([int(c)for c in str(n)])