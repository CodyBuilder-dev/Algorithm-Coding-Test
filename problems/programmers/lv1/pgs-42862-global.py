"""
카테고리 : 그리디로 풀면 막히는 문제

아이디어 :
1. 모든 경우에 대해서 완탐을 수행할 수 있도록 코드를 짜야 함
-> 이때, 자기자신이 잃어버리면, 그사람은 reserve에서 제외한다
3. 
"""

maxima = -10

def dfs(n,lost,reserve) :
    global maxima 
    if len(lost) == 0 :
        maxima = n
        return 

    if len(reserve) == 0 :
        if maxima <= n - len(lost) :
            maxima = n -len(lost)
        return 

    for i in reserve :
        for j in [-1,1] :
            if i + j in lost :
                newReserve = list(filter(lambda x : x != i,reserve))
                newLost = list(filter(lambda x : x != i+j,lost))
                print(newLost,newReserve)
                dfs(n,newLost,newReserve)
                
def solution(n, lost, reserve):
    global maxima
    inter =set(lost).intersection(set(reserve))
    for i in inter :
        lost.remove(i)
        reserve.remove(i)
    print(lost)
    dfs(n,lost,reserve)
    if maxima < n - len(lost) :
        maxima = n -len(lost)

    return maxima

n= 5
lost = [2, 4]
reserve = [1, 3, 5]

n = 5
lost = [2, 4]
reserve= [3]

n = 3
lost = [3]
reserve = [1]

n = 7
lost = [1,2,3]
reserve = [5,6,7]

result = solution(n, lost, reserve)
print(result)