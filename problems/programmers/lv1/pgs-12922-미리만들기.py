"""
제목 : 수박수박수박수박수박수?
"""

def solution(n) :
    answer = "수박"*n
    return answer[:n]

print(solution(10001))
