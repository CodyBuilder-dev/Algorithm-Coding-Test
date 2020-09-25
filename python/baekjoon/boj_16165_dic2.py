"""
접근방법 : 
1. 맵을 이용한 접근
2. 트라이를 이용한 접근(아마도?)
"""

N,M = map(int,input().split())

girlGroup = {}
memberGroup = {}
for i in range(N) :
    groupName, groupNum = input(), int(input())
    girlGroup[groupName] = {}
    for j in range(groupNum) :
        memberName = input()
        girlGroup[groupName][memberName] = 1
        memberGroup[memberName] = groupName

for i in range(M) :
    name, type = input(),int(input())
    if type == 0 : #팀일 경우 사전순으로 한명씩 출력
        for k in sorted(girlGroup[name]) :
            print(k)
    else : # 멤버가 속한 팀의 이름 출력
        print(memberGroup[name])
# print(girlGroup)

