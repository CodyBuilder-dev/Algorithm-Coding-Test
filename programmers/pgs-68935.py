"""
제목 : 3진법 뒤집기

카테고리 : 진법처리

아이디어 : 
1. 숫자를 3진법으로 표현
-> 3나누면서 나머지를 붙여나가는 방식
2. 문자열로 나타낸 후 뒤집기

3. 문자열 -> 10진수 숫자
"""

def dec2tri(n,reverse = False) :
    triStr = ""
    while n > 0 :
        triStr += str(n%3)
        n //= 3
    if reverse : return triStr
    else : return triStr[::-1] 

def tri2dec(n,reverse = True) :
    dec = 0
    for i,v in enumerate(n) :
        dec += 3**i * int(v)
    return dec

def solution(n):
    tri = tri2dec(dec2tri(n))
    
    return tri

n = 45
n = 125

print(solution(n))