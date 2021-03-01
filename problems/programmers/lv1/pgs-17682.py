"""
주제 : 문자열 파싱

아이디어 : 
1. 기회는 3번으로 제한되므로 길이 3짜리 배열로 충분
2. 문자열을 for문 돌면서 읽어 배열에 적절한 변환
    -> 0~9까지는 괜찮은데, 10을 어떻게 처리할 것인가?>

구현 : if-else

문제점 :코드가 너무 지저분하다
"""

def solution(dartResult) :
    scoreList =[0] * 3
    nextScoreIdx = 0
    tenFlag = False

    for idx,char in enumerate(dartResult) :
        # 숫자 처리
        if ord(char) >= 47 and ord(char) <= 57 : 
            if char == '1' :
                tenFlag = True 
            elif char == '0' :
                if tenFlag :
                    scoreList[nextScoreIdx] = 10
                    nextScoreIdx += 1
                    tenFlag =False
                else :
                    scoreList[nextScoreIdx] = 0
                    nextScoreIdx += 1
                    tenFlag =False
            else :
                scoreList[nextScoreIdx] = int(char)
                nextScoreIdx += 1
                tenFlag =False
            
            
        else : 
            if tenFlag :
                scoreList[nextScoreIdx] = 1
                nextScoreIdx += 1
                tenFlag =False
        # 연산자 처리
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
dartResult = "1D2S#10S"
dartResult = "1D2S0T"
result = solution(dartResult)
print(result)
