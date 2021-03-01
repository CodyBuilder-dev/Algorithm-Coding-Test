"""
요구조건
1. 이미 순서가 정해진 숫자가 있다
2. 숫자 k개를 제거해서 가장 큰 수를 만들어라

접근법 1: 브루트 포스
1. 2개를 임의로 뽑는다( 100만C2 = 시간 초과!)
2. 리스트에 보관한다
3. 최종적으로 보관된 리스트를 정렬 

접근법 2 : 그리디
1. 제일 큰 숫자 위치 파악 
2. 앞에 남은 숫자랑 지울수 있는 개수 비교
-> 남은 숫자 > 지우는 개수 : 두번째 큰 수에 대해 반복
-> 남은 숫자 = 지우는 개수 : 지우면 땡!
-> 남은 숫자 < 지우는 개수 : 지우고 뒷부분에 대해 다시 반복
"""

def findMaxIndex(number) :
    return number.index(max(number))

def findSecondIndex(number) :
    sortedNumber = []
    for i,num in enumerate(number) :
        sortedNumber.append((int(num),i))
    sortedNumber = sorted(sortedNumber,key=lambda x: (-x[0],x[1]))    
    return sortedNumber[1][1]

# def solution(number, k):
#     sortedNumber = []
#     for i,num in enumerate(number) :
#         sortedNumber.append((int(num),i))
#     sortedNumber = sorted(sortedNumber,key=lambda x: (-x[0],x[1]))

#     resultNum = ""
#     resultLen = len(number) - k
#     while len(number) != resultLen :
#         leftOfMax = sortedNumber[0][1]
#         if leftOfMax > k :
#             sortedNumber.pop(0)
#         elif leftOfMax < k :
#             sortedNumber.pop(0)
#             resultNum.append(number[leftOfMax])
#             number = number[leftOfMax : ]
            
#             k -= leftOfMax
#         else : 
#             resultNum.append(number[l])
        
#     return resultNum



def solution(number, k):
    resultNum = [0]*len(number)

    leftOfMax = findMaxIndex(number)

    def doTask(number,k,leftOfMax) :
        if leftOfMax > k :
            resultNum[leftOfMax] = number[leftOfMax]
            doTask(number[:leftOfMax]+number[leftOfMax+1:],k,findSecondIndex(number))
        elif leftOfMax < k :
            resultNum[leftOfMax] = number[leftOfMax]
            solution(number[leftOfMax+1:],k-leftOfMax)
        else :
            resultNum[leftOfMax:] = number[leftOfMax:]
    
    
    doTask(number,k,leftOfMax)
    return resultNum
    
number = "1924"
k = 2

number = "1231234"
k = 3

print(solution(number, k))