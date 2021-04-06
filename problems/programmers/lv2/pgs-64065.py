"""
제목 : 튜플

아이디어 :
(1) 일단 문자열을 파싱한다
- 맨 끝의 {}를 뗀다
-
(2) 정렬한다
- 길이순으로 오름차순 정렬한다
- value를 별도의 order_dict에 넣는다
- order_dict순서로 정렬한다
"""
import re

def solution(s):
    hash = {}
    s = re.findall('\d+[,\d]*',s)
    s = sorted(s,key=lambda x:len(x))

    for c in s:
        c = c.split(',')
        if len(c) == 1: hash[c[0]] = 1
        else:
            for x in c:
                if hash.get(x): continue
                else: hash[x] = list(hash.values())[-1]+1
    return list(map(int,hash.keys()))

print(solution("{{2},{2,1},{2,1,3},{2,1,3,4}}"))
print(solution("{{4,2,3},{3},{2,3,4,1},{2,3}}"))