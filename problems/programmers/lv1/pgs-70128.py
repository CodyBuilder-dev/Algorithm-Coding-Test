"""
제목 : 내적

아이디어 : zip을 이용한 elementwise 연산 구현
"""
def solution(a, b):
    return sum([x*y for x,y in zip(a,b)])

print(solution([1,2,3,4],	[-3,-1,0,2]	))
print(solution([-1,0,1],	[1,0,-1]	))