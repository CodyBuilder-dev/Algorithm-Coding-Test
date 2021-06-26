"""
제목 : [3차] n진수 게임
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
    i = 0
    while len(answer) < m*t:
        answer += dec2n(i,n)
        i += 1

    return ''.join(answer[p-1:m*t:m])

print(solution(2,4,2,1))
print(solution(16,16,2,1))
print(solution(16,1000,100,100))


