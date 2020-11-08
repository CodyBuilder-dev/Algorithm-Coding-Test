"""
접근 : 이진탐색을 돌자

구현 : 
1. binarySearch(value,data)로만 접근 -> 시간초과
2. binarySearch(value,left,right)로 접근 -> 이건 정답
"""
def binarySearch(value,data) :
    if len(data) < 1 :
        return False

    leftIdx = 0
    rightIdx = len(data) - 1
    midIdx = (leftIdx + rightIdx)//2

    if value < data[midIdx] :
        return binarySearch(value,data[:midIdx])
    elif value > data[midIdx]:
        return binarySearch(value,data[midIdx+1:])
    else :
        return True

def binarySearch2(value,left,right) :
    if (left > right) : return 0
    mid = (left+right) // 2
    if(value > target_list[mid]) :
        return binarySearch2(value,mid+1,right)
    elif (value < target_list[mid]) :
        return binarySearch2(value,left,mid-1)
    else :
        return 1

if __name__ == "__main__" :
    n = int(input())
    target_list = list(map(int,input().split()))
    target_list = sorted(target_list)
    m = int(input())
    source_list = list(map(int,input().split()))
    
    for source in source_list :
        # print(1 if binarySearch(source,target_list) else 0)
        print(binarySearch2(source,0,len(target_list)-1))
    