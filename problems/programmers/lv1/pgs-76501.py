"""
제목 : 음양 더하기
"""
def solution(absolutes, signs):
    return sum([absolute if sign else -absolute for sign,absolute in zip(signs,absolutes)])

print(solution([4,7,12],	[True,False,True]))
print(solution([1,2,3],	[False,False,True]))