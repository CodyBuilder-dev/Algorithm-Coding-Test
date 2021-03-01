import re

def solution(dartResult) :
    scoreList = re.findall("\d+",dartResult) # 문자열 내에서 패턴과 일치하는 모든 부분
    scoreList = list(map(int,scoreList))
    nextScoreIdx = 0
    for char in dartResult :
        
        if ord(char) >= 48 and ord(char) <= 57 :
            continue
        else :
            if char == 'S' or char == 'D' or char == 'T' :
                nextScoreIdx +=1
        
            if char == 'S' :
                scoreList[nextScoreIdx-1] **= 1
            elif char == 'D' :
                scoreList[nextScoreIdx-1] **= 2
            elif char == 'T' :
                scoreList[nextScoreIdx-1] **= 3
            elif char == '*' :
                if nextScoreIdx >= 2 : 
                    scoreList[nextScoreIdx-1] *=2
                    scoreList[nextScoreIdx-2] *=2
                else :
                    scoreList[nextScoreIdx-1] *= 2
                
            elif char == '#' :
                scoreList[nextScoreIdx-1] *= -1
    return sum(scoreList)

dartResult = "1S2D*3T"
result = solution(dartResult)
print(result)