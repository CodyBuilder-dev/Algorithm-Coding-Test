"""
접근법 : 
1. 숫자가 3개 뿐이므로, 일반적인 3진법으로 진행한다
2. 다만 자연수 뿐이므로, d-1을 해서 적용한다
"""

def dec2tri(d) :
    t = []
    c = [1,2,4]

    while d != 0 :
        d -= 1
        namuzi = d%3
        mok = d//3
        
        t.append(c[namuzi])
        d = mok
        
    return ''.join(map(str,t[::-1]))


def solution(n):
    answer = dec2tri(n)
    return answer

for n in range(1,11) :
    print(solution(n))

"""
1 -> 0,1 -> 1
2 -> 0,2 -> 2
3 -> 1,0 -> 10
4 -> 1,1 -> 11
5 -> 12
6 -> 20
"""
