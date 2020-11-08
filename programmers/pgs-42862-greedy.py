"""
카테고리 : 탐욕

아이디어 : 그리디는, 어느 쪽을 먼저 탐욕적으로 제거하기로 잡느냐가 핵심
1. 사람은 2종류가 있다
-> 양쪽에서 빌릴 수 잇는 사람 / 한쪽에서만 빌릴 수 있는 사람
2. 한쪽에서 빌릴 수 있는 사람을 먼저 주고, 양쪽에서 빌릴 수 있는 사람을 다음으로 준다

"""

def solution(n, lost, reserve):
    maxima = -10
    
    # 중복 제거
    lost = sorted(lost)
    reserve = sorted(reserve)

    inter = set(lost).intersection(set(reserve))
    for i in inter :
        lost.remove(i)
        reserve.remove(i)

    # 분실자를, 두유형으로 분류
    noSide = []
    singleSide = []
    doubleSide = []
    
    for l in lost :
        if l - 1 in reserve and l + 1 in reserve :
            doubleSide.append(l)
        elif l - 1 in reserve or l + 1 in reserve :
            singleSide.append(l)
        else :
            noSide.append(l)

    # 한쪽에서만 빌리는 경우 제거
    for l in singleSide :
        if l - 1 in reserve :
            lost.remove(l)
            reserve.remove(l-1)
        elif l + 1 in reserve :
            lost.remove(l)
            reserve.remove(l+1)
    
    for l in doubleSide :
        if l - 1 in reserve :
            lost.remove(l)
            reserve.remove(l-1)
        elif l + 1 in reserve :
            lost.remove(l)
            reserve.remove(l+1)

    # 양쪽에서 빌리는 경우 제거
    return n - len(lost)

n = 7
lost = [1,2,3]
reserve = [5,6,7]

result = solution(n, lost, reserve)
print(result)