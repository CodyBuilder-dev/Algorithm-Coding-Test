"""
제목 : 위장

아이디어 :
(1) 경우의 '수'만 계산하면 되므로, 굳이 구현을 안 해도 풀 수 있지 않을까?

-> 공식이 명확히 있으면 공식을 쓰면 되지만, 공식이 없으면 구현해야 한다

(2) 의상의 카테고리가 나뉘어져 있으므로, 경우의 수는 아래와 같다
- 옷을 1개 입는 경우
    -> 카테고리 2개 중 택 1 -> 해당 카테고리 경우의 수
- 옷을 2개 입는 경우
    -> 카테고리 2개 중 택 2 -> 해당 카테고리 경우의 수
- 옷을 3개 입는 경우
    -> 카테고리 3개 중 택 3 -> 해당 카테고리 경우의 수
- ...
- 옷을 N개 입는 경우
    ->

-아니면 그냥, 각 카테고리별로 0개 또는 1개씩 뽑는 경우의 수 를 한 후,
모두 안 뽑는 경우만 1개 제외하면 된다
"""
def make_category(clothes):
    clothes_to_type = dict()
    for cloth in clothes :
        if not clothes_to_type.get(cloth[1]):
            clothes_to_type[cloth[1]] = []
        clothes_to_type[cloth[1]].append(cloth[0])
    return clothes_to_type


def solution(clothes):
    category = make_category(clothes)
    total = 1
    for k in category :
        total *= len(category[k])+1

    return total -1
clothes = [["yellowhat", "headgear"], ["bluesunglasses", "eyewear"], ["green_turban", "headgear"]]
print(solution(clothes))