"""
제목 : 행렬의 곱셈

구현 : 그냥 list로 구현할 수 있다
(1) 그냥 반복문
- 4중 for문으로 구현해야 할 수도 있음 ㄷㄷ
(2)  Transpose를 이용한 연산 간략화
- sum_list만 구현해 놓으면 알아서 해결됨
"""
def inner_product(a,b):
    return sum([i*j for i,j in zip(a,b)])

def solution(arr1, arr2):
    arr2 = [list(x) for x in zip(*arr2)]
    result = [[0]*len(arr2) for x in range(len(arr1))]
    
    for i in range(len(arr1)):
        for j in range(len(arr2)):
            result[i][j] = inner_product(arr1[i],arr2[j])
    
    return result

# 테스트 케이스
example = [[1,2],[3,4]]
print(list( map(list, zip(*example))))

print(solution([[1, 4], [3, 2], [4, 1]],[[3, 3], [3, 3]]),[[15, 15], [15, 15], [15, 15]])
print(solution([[2, 3, 2], [4, 2, 4], [3, 1, 4]],[[5, 4, 3], [2, 4, 1], [3, 1, 1]]),[[22, 22, 11], [36, 28, 18], [29, 20, 14]])