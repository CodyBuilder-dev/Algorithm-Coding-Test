"""
제목 : 스킬트리

아이디어 : 스택 사용
- 문자열 중, 특정 값이 반드시 먼저 오도록 하기 위해서는 스택을 사용할 수 있다
- 값을 앞에서부터 검사한다
    - 스킬트리에 없는 스킬의 순서는 무시해도 된다
    - 스킬트리에 있는 스킬은 스택에 스킬트리의 이전 값이 없으면 불가능하다
- 시간 복잡도 : O(MN)

구현 : 해시를 이용
- 스킬명을 key로, 그 앞에 나오는 스킬을 value로 갖는 해시를 만들어 쓴다
"""
def solution(skill, skill_trees):
    skill_order = {v: skill[i-1] for i, v in enumerate(skill)}
    skill_order[skill[0]] = -1

    count = 0
    for tree in skill_trees:
        stack = [-1]
        is_available = True
        for s in tree:
            if skill_order.get(s):
                if stack[-1] == skill_order[s]:
                    stack.append(s)
                else:
                    is_available = False
                    break
        if is_available:
            count +=1
    return count

# 테스트 케이스
print(solution("CBD",["BACDE", "CBADF", "AECB", "BDA"]))