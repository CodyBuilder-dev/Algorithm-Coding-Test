import re

def solution(dartResult) :
    scoreList = re.findall("\d+",dartResult) # 문자열 내에서 패턴과 일치하는 모든 부분
    scoreList = list(map(int,scoreList))
    print(scoreList)

    bonusList = re.findall("[SDT][*#]?",dartResult)
    bonusDict = {'S':1,'D':2,'T':3}
    optionDict = {'*':2,'#':-1}

    for index,bonus in enumerate(bonusList) :
        print(index,bonus)
        print(scoreList)
        scoreList[index] **= bonusDict[bonus[0]]
            
        if len(bonus) == 2 :
            if bonus[1] == '*' :
                if index  >= 1 :
                    scoreList[index - 1] *= optionDict[bonus[1]]
                    scoreList[index] *= optionDict[bonus[1]]
                else :
                    scoreList[index] *= optionDict[bonus[1]]                
            elif bonus[1] == '#' :
                scoreList[index] *= optionDict[bonus[1]]                
    return sum(scoreList)

dartResult = "1S2D*3T"
dartResult = "1D2S#10S"
result = solution(dartResult)
print(result)