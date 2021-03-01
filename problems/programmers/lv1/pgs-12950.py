"""
제목 : 행렬의 덧셈
"""

def solution(arr1, arr2):
    result = []
    for x,y in zip(arr1,arr2) :
        temp1 = []
        for xx,yy in zip(x,y) :
            temp1.append(xx+yy)
        result.append(temp1)
    return result

arr1 = [[1,2],[2,3]]
arr2 = [[3,4],[5,6]]

arr1 = [[1],[2]]
arr2 = [[34],[56]]
print(solution(arr1,arr2))
