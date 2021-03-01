from collections import Counter

def solution(s):
    c = Counter(s)
    return c['y']+c['Y'] == c['p'] + c['P']

s = "pPooyY"
print(solution(s))
#print(help(Counter)) 