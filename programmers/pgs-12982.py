"""
접근법 : 그리디로 접근
1. 목적은 지원받는 부서수를 최대한 늘리는 것이다
2. 그렇다면 가장 적은 돈을 신청한 부서부터 지원해주면 된다
"""

def solution(d, budget):
    usedBudget = 0
    supportedDepart = 0
    for i in sorted(d) :
        if i + usedBudget <= budget :
            usedBudget,supportedDepart = usedBudget +i, supportedDepart +1
    return supportedDepart

d = [1,3,2,5,4]	
budget = 9

print(solution(d,budget))