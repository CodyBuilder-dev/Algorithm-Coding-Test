"""
접근방식 : 
1. Ascending, Descending에 대해 각각 한번씩 판별
정답여부 : Y
"""

def set_number() : # 일렬로 들어오는 입력 받기
    data = list(map(int,input().split()))
    return data

def check_direction(data) :
    ascending = [1,2,3,4,5,6,7,8]
    descending = [8,7,6,5,4,3,2,1]

    isAsc = True
    for val in  [sum(x) for x in zip(data,descending)] : # 파이썬 리스트는 append이다
        if val != 9 : 
            isAsc = False
            break

    if isAsc : return 0

    isDesc = True
    for val in  [sum(x) for x in zip(data,ascending)] :
        if val != 9 : 
            isDesc = False
            break

    if isDesc : return 1
    return 2


if __name__ == "__main__" :
    cache = ["ascending","descending","mixed"]
    data = set_number()
    print(cache[check_direction(data)])