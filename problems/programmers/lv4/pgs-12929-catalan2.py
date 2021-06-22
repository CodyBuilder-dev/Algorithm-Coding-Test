"""
제목 : 올바른 괄호의 갯수

아이디어 : 카탈란 수로 풀린다는걸 알고 풀면 어처구니 없을 정도로 쉽게 풀린다
(자세한 증명에 대한 공부는 블로그에)

구현 : combination 구현
-> 그냥 combination쓰면 시간초과
-> 수식으로 풀어야 함
"""
#from itertools import combinations
from functools import reduce

def solution(n):
    if n == 1: return 1
    # 그냥 구하면 시간초과가 난다. 식으로 풀어야 한다
    # return len(list(combinations(range(2*n),n)))//(n+1)
    bunza = reduce(lambda x,y: x*y,range(1,2*n+1))
    bunmo = reduce(lambda x,y: x*y,range(1,n+1))**2 * (n+1)
    return bunza//bunmo

print(solution(1))
print(solution(4))
print(solution(14))