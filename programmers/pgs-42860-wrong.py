"""
접근법 : 
알파벳의 왼쪽에서 오른쪽으로 진행하며, 그때그때 최선의 선택을 한다
1. 포인터를 옮긴다. 
2. 알파벳이 같으면 pass
2. 알파벳이 다르면 포인터 선택
3. 현재 포인터에서 다음 포인터까지 최단거리 선택
3. 도착하면 알파벳 최단거리 선택

-> 문제점 : 왼->오가 최고 빠르다는 보장이 없음

"""

alphaStr = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

def solution(name):
    aName = "A"*len(name)

    cnt = 0
    pt = 0
    for i,v in enumerate(name) :
        if name[i] == aName[i] :
            continue
        else :
            cnt += min(i-pt,len(name)-i+pt)
            charDiff = max(ord(name[i])-ord(aName[i]), ord(aName[i])-ord(name[i]))
            cnt += min(26-charDiff,charDiff)
            pt = i
    return cnt


name = "JEROEN"
name = "JAN"
name = "JAZ"
print(solution(name))