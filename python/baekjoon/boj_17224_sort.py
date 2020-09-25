"""
접근방법 : 정렬 이용
1. 어려운 문제순으로 오름차순 정렬
2. 그리디하게 풀수있을 때 까지 푼다
3. 안되면 쉬운 문제부터 다시 오름차순 
"""

N,L,K = map(int,input().split())

questionList = []
for i in range(N) :
    easy, hard = map(int,input().split())
    questionList.append((hard,easy))

questionList = sorted(questionList)

sum = 0
cnt = 0
for i in range(N) :
    if cnt >= K :
        break

    if questionList[i][0] <= L :
        sum += 140
        cnt += 1
    elif questionList[i][1] <= L :
        sum += 100
        cnt += 1
    else :
        continue

print(sum)