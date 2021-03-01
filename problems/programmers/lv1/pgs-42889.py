def solution(N,stages) :
    peopleOnStage = [0] * (N+2)
    
    for num in stages :
        peopleOnStage[num] += 1
    
    failPersent = {}
    bunMo = len(stages)
    for i in range(1,N+1) :
        if bunMo > 0 :
            failPersent[i] = peopleOnStage[i]/bunMo
        if bunMo ==  0 :
            failPersent[i] = 0        
        bunMo -= peopleOnStage[i]


    # dict를 실패율 순으로 정렬
    # failPersentSorted = [(value,key) for key,value in failPersent.items()]
    # failPersentSorted = [ x[1] for x in sorted(failPersentSorted,key = lambda x: (-x[0],x[1]))]
    failPersentSorted = sorted(failPersent,key = lambda x : failPersent[x], reverse= True)
    return failPersentSorted


N = 8
stages = [3, 3, 3, 3, 3, 3, 3, 3]
result = solution(N,stages)
print(result)