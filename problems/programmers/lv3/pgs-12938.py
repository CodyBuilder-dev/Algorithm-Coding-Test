"""
제목 : 최고의 집합
"""
def solution(n, s):
    if s < n: return [-1]
    mok, namuzi = s // n , s % n

    return [mok]*(n-namuzi) + [mok+1]*namuzi

print(solution(2,9))
print(solution(2,1))
print(solution(2,8))
