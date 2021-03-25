"""
제목 : 막대기

아이디어 : 비트마스킹을 반드시 쓸 것
"""

def solution(X):
    return bin(X).count('1')

X = int(input())
print(solution(X))