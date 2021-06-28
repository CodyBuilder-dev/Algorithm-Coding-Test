"""
제목 : 불량 사용자

아이디어 : 정규표현식에 정확히 동일한 개념의 연산자가 있다...

- 크기가 작으므로, 그냥 완전탐색 돌아도 된다

- for문으로 처리?
    - banned id의 길이가 정해져있지 않으므로 어려움
- 재귀로 처리
    - 1번부터 돌면서 1번 매칭되는거 찾기
        - 찾으면 그 인덱스는 제외하고, 다른 인덱스에 대해 다시 2번 매칭되는거 찾기
            - 무한반복

구현 : 생각이 안나서 글로벌 변수로 처리리
"""
importre

result = set()
def dfs(user_ids, banned_ids,banned_idx, checked):
    global result
    # 더이상 검사할 밴 아이디가 없으면 탈출
    if banned_idx >= len(banned_ids):
        if sum(checked) == len(banned_ids):
            return result.add(tuple([i for i,v in enumerate(checked) if v]))
        else:
            return


    banned_id = banned_ids[banned_idx]
    for i,user_id in enumerate(user_ids):
        if not checked[i] and re.fullmatch(banned_id,user_id):
            checked[i] = True
            dfs(user_ids,banned_ids,banned_idx+1,checked)
            checked[i] = False
    return

def solution(user_ids, banned_ids):
    global result
    result = set()


    for i,banned_id in enumerate(banned_ids):
        banned_ids[i] = banned_id.replace('*','\w')

    for i,user_id in enumerate(user_ids):
        checked = [False] * len(user_ids)
        dfs(user_ids,banned_ids,0,checked)

    return len(result)

print(solution(["frodo", "fradi", "crodo", "abc123", "frodoc"],["fr*d*", "abc1**"]))
print(solution(["frodo", "fradi", "crodo", "abc123", "frodoc"],	["*rodo", "*rodo", "******"]))
print(solution(["frodo", "fradi", "crodo", "abc123", "frodoc"],	["fr*d*", "*rodo", "******", "******"]))
print(solution(["fdddd", "fradi", "crodo", "abc123", "frodoc"],["fr*d*", "abc1**"]))
print(solution(["1", "2", "3", "4", "5"],["f", "a"]))