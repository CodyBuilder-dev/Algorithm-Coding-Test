"""
제목 : [3차] n진수 게임

접근법 :
1. 진법 문자열를 생성하는 프로그램을 만든다
-> 0,1,2,3,...의 십진수를 하나씩 대응되는 n진수로 변환해 사용

2. 만들어진 n진법 문자열을 주기적으로 추출하면 끝
-> m명이서 진행하는데, 내가 말할 t번만큼 미리 구해야 한다
-> 즉 m*t 길이만큼 전체를 구해 놓고 내가 말할 부분만 추출해내면 된다
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



