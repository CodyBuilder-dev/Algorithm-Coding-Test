"""
제목 : 이름궁합 테스트
접근방법 : 하나씩 구현
1. 이름을 받아서 list로 만들기
2. while이나 재귀나 dp를 통해 리스트 줄여나가기
3. len(리스트) == 2일때까지 반복하기
4. list[0] + list[1]로 확률 구하기
"""

def getCharlistFromName(nm1,nm2) :
    cmLength = min(len(nm1),len(nm2)) 
    charList = []
    for i in range(cmLength) :
        charList.append(nm1[i])
        charList.append(nm2[i])
    
    if len(nm1) > len(nm2) :
        for i in range(cmLength,len(nm1)) :
            charList.append(nm1[i])
    elif len(nm1) < len(nm2) :
        for i in range(cmLength,len(nm2)) :
            charList.append(nm2[i])
    
    return charList

def getNumlistFromCharlist(charmap,charlist) :
    numlist = []
    for char in charlist :
        numlist.append(charmap[ord(char)-65])
    return numlist
def getPercentFromNumlist(numlist) :
    while len(numlist) > 2 :
        for i in range(1,len(numlist)) :
            numlist[i-1] = (numlist[i-1]+numlist[i])%10
        numlist.pop()
        # print(numlist)
    percent = numlist[0]*10 + numlist[1]
    percent = str(percent)  +'%'
    return percent
def solution(charmap,nm1,nm2) :
    charlist = getCharlistFromName(nm1,nm2)
    numlist = getNumlistFromCharlist(charmap,charlist)
    percent = getPercentFromNumlist(numlist)

    return percent

if __name__ == "__main__" :
    n,m = map(int,input().split())
    nm1,nm2 = input().split()

    charmap = [3,2,1,2,4,3,1,3,1,1,
                3,1,3,2,1,2,2,2,1,2,
                1,1,1,2,2,1]

    print(solution(charmap,nm1,nm2))