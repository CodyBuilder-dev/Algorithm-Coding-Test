"""
접근법 :
1. 진법 문자열를 생성하는 프로그램을 만든다
-> 바로 만들기 
-> 십진수를 변환하기

2. 진법 문자열을 만든후 주기적으로 추출하면 끝
-> m명이서 진행하는데, t번만큼 말해야 하므로 m*t만큼의 개수를 구해야 한다

"""

def dec2n(d,n) :
    answer = []
    if d == 0 :
        answer.append('0')
    while d != 0 :
        res= d%n
        if res < 10 :
            answer.append(chr(res+48))
        else :
            answer.append(chr(res+55))
        d //= n

    return ''.join(answer[-1::-1])


def solution(n, t, m, p):
    answer = ""
    for i in range(m*t) :
        answer += dec2n(i,n)
    
    answer2 = ""
    for i in range(p-1,m*t,m) :
        answer2 += answer[i]
        
    return answer2
n,t,m,p = 2,4,2,1
n,t,m,p = 16,16,2,1
print(solution(n,t,m,p))



