"""
아이디어 :
(1) 트리를 구현하고, seller를 순차적으로 탐색하며 노드로부터 루트까지 순차적으로 올라가면서 찾는다
-> 10^5 * 10^4
-> 기각
(2) 트리를 구현하고, seller에 값을 다 할당한 후, 모든 리프로부터 루트까지 한번에 찾는다
- 리프 탐색은 어떻게 구현할까?
-> 10^4
(3) 트리를 구현하고, seller에 값을 다 할당한 후, DFS를 이용해 루트에서 왔다가 간다
- 노드 클래스를 만들고, 리스트에 저장한다 (X)
- 순서 있는 딕셔너리로 트리를 만드는게 맞다
- 노드는 내가 먹는 값, 자식의 정보만 저장한다
- DFS를 통해 리프까지 간다 -> 내 노드가 남겨먹는 값을 구한다 -> 반환할 때는 부모에게 줄 값을 반환한다
-> 10^4

예외케이스
세금으로 받은 이익이 9원이고 내가 번 돈이 1원이면
-> 한번에 계산하면 10원이 되어 세금을 떼인다
-> 따로 계산하면 세금을 떼이지 않는다

처음에 다 더하고 시작하는 거의 문제점
-> 논리적으로 틀림, 한 건의 이득에 대해서 부모로 전달해야 함
"""

def dfs(tree,current):
    # 내려간다
    # 부모에 돌려줄 값을 반환한다
    tax = 0
    tax += tree[current]["revenue"]//10
    tree[current]["revenue"] -= tree[current]["revenue"]//10

    for c in tree[current]["child"]:
        gift = dfs(tree,c)
        tax += gift//10
        tree[current]["revenue"] += gift - gift//10

    return tax

def create_tree(enroll, referral, seller, amount):
    tree = dict.fromkeys(["-"] + enroll)
    for k in tree:
        tree[k] = {"revenue": 0, "child": []}

    for ref,en in zip(referral,enroll):
        tree[ref]["child"].append(en)

    for s,a in zip(seller,amount):
        tree[s]["revenue"] += a*100
    return tree


def solution(enroll, referral, seller, amount):
    tree = create_tree(enroll, referral, seller, amount)
    dfs(tree,"-")

    answer = []
    for t in tree:
        answer.append(tree[t]["revenue"])
    return answer[1:]


# 테스트케이스
print(solution(["john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"],
               ["-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"],
               ["young", "john", "tod", "emily", "mary"],
               [12, 4, 2, 5, 10]))

print(solution(["john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"],
               ["-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"],
               ["sam", "emily", "jaimie", "edward"],
               [2, 3, 5, 4]))

print(solution(["a"],["-"],["a"],[1]))
print(solution(["a"],["-"],["-"],[1]))