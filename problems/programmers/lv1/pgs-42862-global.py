"""
제목 : 체육복

아이디어 :
(1) 중복 제거
- 이때, 보유자 자기자신이 잃어버리면, 그사람은 reserve에서 제외한다

(2) 모든 경우에 대해서 완탐을 수행할 수 있도록 코드를 짜야 함

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

# 테스트 케이스
print(solution(5,[2,4],[1,3,5]),5)
print(solution(5,[2,4],[3]),4)
print(solution(3,[3],[1]),2)
print(solution(7,[1,2,3],[5,6,7]),4)