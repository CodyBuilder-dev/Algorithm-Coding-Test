"""
1. 이중 for문으로 두개 뽑기
2. 뽑은 결과의 합이 <=200 이므로, 200짜리 배열 만들기
3. 배열에서 >=1 애들만 찾아서 넣기
"""
def solution(numbers) :
    exists = [0] * 201
    for i in range(len(numbers)) :
        for j in range(i+1,len(numbers)) :
            exists[numbers[i] + numbers[j]] += 1

    answer = []
    for i in range(0,201) :
        if exists[i] >= 1:
            answer.append(i)

    return answer

numbers = [2,1,3,4,1]
numbers = [5,0,2,7]
result = solution(numbers)
print(result)