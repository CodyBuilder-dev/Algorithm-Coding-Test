"""
제목 : 스킬트리

아이디어 : 정렬
- 스킬트리에서의 인덱스를 보존한 채로 정해진 순서에 따라 정렬한다
- 스킬트릐에서의 인덱스 증감과 정해진 순서가 일치하지 않으면 불가능한 것이다
    - 예시: CBD순으로 와야하는데, CBD순으로 정렬했더니 인덱스가 2 1 3이다 -> 불가능한 스킬트리

-> 문제점 :
    - 스킬을 순서대로 안 배운 경우는 잡을 수 있다
    - 그러나 스킬을 아예 안 배우고 그 다음 걸 배우는건 잡을 수 없다
"""

def sort_key(skill_order,x):
    if skill_order.get(x):
        return skill_order[x]
    else:
        return len(skill_order)+987654321
def solution(skill, skill_trees):
    skill_order = {v:i+1 for i,v in enumerate(skill)}
    count = 0
    for tree in skill_trees:
        sorted_tree = sorted([(v,i) for i,v in enumerate(tree)],key=lambda x:sort_key(skill_order,x[0]))
        is_correct = True
        for i,v in enumerate(sorted_tree[0:-1]):
            if (sorted_tree[i][0] in skill_order and sorted_tree[i+1][0] in skill_order) \
                and sorted_tree[i][1] > sorted_tree[i+1][1]:
                is_correct = False
                break
        if is_correct: count +=1

    return count

print(solution("CBD",["BACDE", "CBADF", "AECB", "BDA"]))
# sort_key