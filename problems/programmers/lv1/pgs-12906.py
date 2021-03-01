def solution(arr):
    # arrSet = set(arr) #단순히 set으로 접근 불가
    answer = []
    prevNum = 0
    for i,num in enumerate(arr) :
        if i == 0 : 
            prevNum = num
            answer.append(num)
        elif num == prevNum :
            continue
        else :
            prevNum = num
            answer.append(num)

    return answer

arr = [1,1,3,3,0,1,1]
print(solution(arr))