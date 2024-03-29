"""
제목 : 순위

요구조건 : 정확히 순위를 매길 수 있는 사람의 수
- 정확한 순위란? N명 중에 본인이 몇위인지 정확히 판단이 되는 것

아이디어 : 정확한 순위를 아는 방법
(1) 내 앞에 몇 명이 있는지, 내 뒤에 몇 명이 있는지 모든 정보가 있다.
(2) 정보가 부족하다면, 적어도 자신에게 승/패한 상대를 따라갔을 때 모든 정보가 획득 가능하다

구현 :
- 인접행렬을 이용한다?
"""

def find_ranking(i,winloss):
    if winloss == 1:
        pass



def solution(n, results):
    wltable = [[0]*(n+1) for i in range(n+1)]
    for result in results :
        wltable[result[0]][result[1]] = 1
        wltable[result[1]][result[0]] = -1

    answer = []
    for i in range(1,n+1):
        #  모든 정보가 있는 경우
        if sum(map(abs,wltable[i])) == n-1:
            answer.append(i)
        else :

    return wltable


n = 5
results = [[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]]
print(solution(n,results))

print(sum(map(abs,[0,-1,1,0,1])))