"""
제목 : 멀쩡한 사각형

카테고리 : 좌표, 최대공약수(유클리드 호제법)

아이디어 : 
1. 좌표계의 아이디어 이용
(0,0) (H-1,W-1)을 지나는 직선
y = H-1/W-1 * x
x = 1 y = H-1/W-1 <- 이게 어디에 위치하는지 파악 필요
x = 2 
..

2. 최대공약수를 통한 좌표 축소(유클리드 호제법)
-> 두 수 a,b의 최대공약수는, a와 a를 b로 나눈 나머지 c의 최대공약수와 같다
-> a = 10 b = 3인 경우, c = 1, a와 b의 최대공약수는 1

"""
import math

def euclidGcd(a,b) :
    if b > a : a,b = b,a
    while b!=0 :
        a = a%b
        a,b=b,a
    return a

def euclidGcdBySub(a,b) :
    while(a!=b):
        if(a>b) : a-=b
        else    : b-=a
    return a

def solution(w,h):
    gcd = euclidGcdBySub(w,h)
    w_hat = w//gcd
    h_hat = h//gcd
    
    totalSq = h_hat*w_hat
    brokenSq = 0
    
    if w_hat <= h_hat :
        for x in range(1,w_hat+1) :
            addSq = math.ceil((h_hat*x/w_hat)) - math.floor(h_hat*(x-1)/w_hat) 
            # addSq = math.ceil((h_hat/w_hat * x)) 의 경우 오답 발생
            brokenSq += addSq
    else :
        for y in range(1,h_hat+1) :
            addSq = math.ceil((w_hat*y/h_hat)) - math.floor(w_hat*(y-1)/h_hat) 
            brokenSq += addSq
        
    return totalSq * gcd**2 - brokenSq * gcd

w = 3
h = 3

# w = 34532
# h = 1323923
print(solution(w,h))
