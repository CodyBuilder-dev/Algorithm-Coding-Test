"""
제목 : 체육복

카테고리 : 탐욕

아이디어 : 그리디는, 어느 쪽을 먼저 탐욕적으로 제거하기로 잡느냐가 핵심
1. 사람은 2종류가 있다
-> 양쪽에서 빌릴 수 잇는 사람 / 한쪽에서만 빌릴 수 있는 사람
2. 한쪽에서 빌릴 수 있는 사람을 먼저 주고, 양쪽에서 빌릴 수 있는 사람을 다음으로 준다
"""
def solution(n, lost, reserve):
    # 경우의 수를 나눠서 접근하면, 정렬은 해도 되고 안해도 됩니다
    # lost = sorted(lost)
    # reserve = sorted(reserve)

    # 중복 제거
    inter = set(lost).intersection(set(reserve))
    for i in inter:
        lost.remove(i)
        reserve.remove(i)

    # 분실자를, 두유형으로 분류
    no_side = []
    single_side = []
    double_side = []

    for l in lost:
        if l - 1 in reserve and l + 1 in reserve:
            double_side.append(l)
        elif l - 1 in reserve or l + 1 in reserve:
            single_side.append(l)
        else:
            no_side.append(l)

    # 한쪽에서만 빌리는 경우 제거
    for l in single_side:
        if l - 1 in reserve:
            lost.remove(l)
            reserve.remove(l - 1)
        elif l + 1 in reserve:
            lost.remove(l)
            reserve.remove(l + 1)

    # 양쪽에서 빌리는 경우 제거
    for l in double_side:
        if l - 1 in reserve:
            lost.remove(l)
            reserve.remove(l - 1)
        elif l + 1 in reserve:
            lost.remove(l)
            reserve.remove(l + 1)

    return n - len(lost)


print(solution(5, [2, 4], [1, 3, 5]), 5)
print(solution(5, [2, 4], [3]), 4)
print(solution(3, [3], [1]), 2)
print(solution(7, [1, 2, 3], [5, 6, 7]), 4)
