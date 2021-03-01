"""
아이디어 : 
1. 각 수포자의 수열을 구현
-> 파이썬의 list 곱하기를 이용한다
2. 수열과 수열을 elementwise로 비교
3. 맞을때마다 개수 +1
"""

def solution(answers):
    supo1 = [1,2,3,4,5] * 2000
    supo2 = [2,1,2,3,2,4,2,5] * 1250
    supo3 = [3,3,1,1,2,2,4,4,5,5] * 1000

    supoCount = [0] * 3
    for i in zip(answers,supo1,supo2,supo3) :
        if i[0] == i[1] :
            supoCount[0] += 1
        if i[0] == i[2] :
            supoCount[1] += 1
        if i[0] == i[3] :
            supoCount[2] += 1
    
    # 최대값과 동일한 모든 수 추출
    maxCount = max(supoCount)
    answer = []
    for index,supo in enumerate(supoCount) :
        if supo == maxCount :
            answer.append(index+1)
    return answer

answers = [1,2,3,4,5]
answers = [1,3,2,4,2]
print(solution(answers))
