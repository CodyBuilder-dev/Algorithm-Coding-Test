"""
제목 : 최대공약수와 최소공배수

아이디어 :
- 최대공약수 : math.gcd 사용
- 최소공배수 : 계산된 gcd를 이용해 계산
"""
from math import gcd

def solution(n, m):
    return gcd(n,m), n*m/gcd(n,m)