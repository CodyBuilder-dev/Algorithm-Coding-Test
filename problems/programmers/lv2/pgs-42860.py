"""

접근법 : 현재 점에서 왼쪽 젤 가까운 곳, 오른쪽 젤 가까운 곳으로 간다
1. 왼쪽거리 계산
2. 오른쪽 거리 계산
3. 둘중 짧은곳으로 고
4. 반복
"""

def solution(name) :
    n = len(name)
    name = list(name)
    aName = ["A"]*n
    cur = 0
    cnt = 0

    while True :
        leftExist,leftDiff = False,0
        rightExist,rightDiff = False,0

        for i in range(cur,cur-n,-1) :
            if name[i%n] != aName[i%n] :
                leftExist = True
                lcharDiff = max(ord(name[i])-ord(aName[i]), ord(aName[i])-ord(name[i]))
                lcharDiff = min(26-lcharDiff,lcharDiff)
                
                break
            else : 
                leftDiff += 1
        
        for j in range(cur,cur+n) :
            if name[j%n] != aName[j%n] :
                rightExist = True
                rcharDiff = max(ord(name[i])-ord(aName[i]), ord(aName[i])-ord(name[i]))
                rcharDiff = min(26-rcharDiff,rcharDiff)
                
                break
            else : 
                rightDiff += 1
        
        if leftDiff < rightDiff :
            aName[i%n] = name[i%n]
        else : 
            aName[j%n] = name[j%n]
        
        if not (leftExist or rightExist) : break

        print("l",leftDiff,"r",rightDiff)
        diff = min(leftDiff,rightDiff)
        print("diff=",diff)
        cnt += lcharDiff if diff == leftDiff else rcharDiff
        cnt += leftDiff if diff == leftDiff else rightDiff
        cur = i if diff == leftDiff else j
        print("cur =",cur)
        

    return cnt

name = "JAZ"
name = "JEROEN"
print(solution(name))