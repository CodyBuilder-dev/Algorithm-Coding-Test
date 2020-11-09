"""
아이디어 :
1. 리스트를 돌면서, 최소 배포일자를 계산한다

2. 길이 100짜리 배열에, 각 일자별 배포가능 개수를 집허넣는다

3. 마지막에 해당 리스트를 출력한다

개선안 : 
math.ceil을 안 쓰고 하는 방법은?
->음수를 쓰면 된..다... 누군진 모르지만 천재아닌가?
"""
import math

def solution(progresses, speeds):
    baePo = [0] * 100
    minimumGongsu = [] # 각 job별 최소공수
    
    for idx, currentRate in enumerate(progresses) :
        gongSu = math.ceil((100 - currentRate)/speeds[idx])
        if idx == 0 : minimumGongsu.append(gongSu)
        else : minimumGongsu.append(max(minimumGongsu[idx-1],gongSu))
    
    print(minimumGongsu)
    for time in minimumGongsu :
        baePo[time] += 1
    
    return list(filter(lambda x:x!=0, baePo))

progresses = [93, 30, 55]
speeds = [1, 30, 5]

# progresses = [95, 90, 99, 99, 80, 99]
# speeds = [1, 1, 1, 1, 1, 1]
print(solution(progresses, speeds))