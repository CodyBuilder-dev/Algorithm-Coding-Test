"""
제목 : 불량 사용자

아이디어 : 정규표현식에 정확히 동일한 개념의 연산자가 있다...

구현 : 경우의 수를 적절히 계산하면 매우 쉽게 풀린다
"""
import re

answer = set()

def extract_ids(result,i,selected):
    if i >= len(result):
        answer.add(tuple(sorted(selected)))
        return

    for id in result[i]:
        if id not in selected:
            selected.append(id)
            extract_ids(result,i+1,selected)
            selected.pop()

    return

def solution(user_ids, banned_ids):
    global answer
    answer = set()
    for i,banned_id in enumerate(banned_ids):
        banned_ids[i] = banned_id.replace('*','\w')

    result = []
    for banned_id in banned_ids:
        temp = []
        for user_id in user_ids:
            if re.fullmatch(banned_id,user_id):
                temp.append(user_id)
        result.append(temp)
    # return result
    extract_ids(result,0,[])
    return len(answer)


print(solution(["frodo", "fradi", "crodo", "abc123", "frodoc"],["fr*d*", "abc1**"]))
print(solution(["frodo", "fradi", "crodo", "abc123", "frodoc"],	["*rodo", "*rodo", "******"]))
print(solution(["frodo", "fradi", "crodo", "abc123", "frodoc"],	["fr*d*", "*rodo", "******", "******"]))
print(solution(["fdddd", "fradi", "crodo", "abc123", "frodoc"],["fr*d*", "abc1**"]))
print(solution(["1", "2", "3", "4", "5"],["f", "a"]))