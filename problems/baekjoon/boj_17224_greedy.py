"""
접근방법 : 전체 탐색
1. 전체를 다 돌면서 hard와 easy 파악한다
2. 개수에 따라 점수를 계산한다
3. 
"""

N,L,K = map(int,input().split())

easy,hard = 0,0
for i in range(N) :
    sub1, sub2 = map(int,input().split())
    if sub2 <= L :
        hard += 1
        continue
    elif sub1 <= L :
        easy += 1

totalHard = min(hard,K)
totalEasy = min(easy,K-totalHard)

print(totalHard*140 + totalEasy * 100)
