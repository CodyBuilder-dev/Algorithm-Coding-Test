"""
카테고리 : 비트마스크

아이디어 : 문자열 두개를 비트마스크 한다

구현 :
1. 정수를 n자리 이진수로 표현
2. 두 수를 비트마스크
3. 결과를 n자리 #으로 표현

"""

def solution(n, arr1, arr2):
    answer = []
    for i in zip(arr1,arr2) :
        v = int(i[0]) | int(i[1])
        v = bin(v)[2:].zfill(n).replace('1','#').replace('0',' ')
        answer.append(v)
    return answer

n = 5
arr1 = [9, 20, 28, 18, 11]
arr2 = [30, 1, 21, 17, 28]

result = solution(n,arr1,arr2)
print(result)