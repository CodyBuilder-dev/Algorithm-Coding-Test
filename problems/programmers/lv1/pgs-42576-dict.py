"""
아이디어 :
1. 완주자 테이블을 for문으로 돈다
2. 매번 in을 돌린다? -> O(NM)이 되어머림

1. 참가자 테이블을 for문으로 돈다
2. 참가자를 dictionary에 넣어 hash map을 만든다
3. 완주자 테이블을 for문으로 돈다
4. 참가자 dictionary에 숫자를 뺀다
5. 최종적으로 dictionary에서 0이 아닌 놈들을 찾는다
-> O(N+M+N)
"""

def solution(participant, completion):
    partDict = {}
    for part in participant :
        if not partDict.get(part) :
            partDict[part] = 0
        partDict[part] += 1
    
    for comp in completion :
        partDict[comp] -= 1

    for key in partDict :
        if(partDict[key] > 0) :
            return key
    

participant = ["leo", "kiki", "eden"]
completion = ["eden", "kiki"]

participant = ["marina", "josipa", "nikola", "vinko", "filipa"]
completion = ["josipa", "filipa", "marina", "nikola"]

result = solution(participant, completion)
print(result)