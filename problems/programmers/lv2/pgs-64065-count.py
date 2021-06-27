"""
제목 : 튜플

아이디어 :
(1) 일단 문자열을 파싱한다
- 맨 끝의 {}를 뗀다

(2) 출현빈도를 센다
"""
import re

def solution(s):
    hash = {}
    s = re.findall('\d+[,\d]*',s)
    s = sorted(s,key=lambda x:len(x))


    for c in s:
        c = c.split(',')
        for x in c:
            if not hash.get(x): hash[x] =0
            hash[x] += 1

    return list(map(int,sorted(hash, key = lambda x:-hash[x])))

print(solution("{{2},{2,1},{2,1,3},{2,1,3,4}}"))
print(solution("{{4,2,3},{3},{2,3,4,1},{2,3}}"))