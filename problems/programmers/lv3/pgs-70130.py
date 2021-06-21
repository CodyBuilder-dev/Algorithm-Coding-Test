"""
아이디어 : 각 원소의 인덱스를 저장하고, 이로부터 스타 수열의 길이를 찾을 수 있다

"""
from pgs70130tc import tc_in,tc_out

def find_starlen(elem,idx_list,array):
    prev_idx = idx_list[0]
    star_len = 0
    if prev_idx > 0:
        prev_position = 1
        star_len += 2
    elif prev_idx == 0 and len(idx_list) > 1 and idx_list[1] >= 2:
        prev_position = 0
        star_len += 2
    else:
        prev_position = 1

    for idx in idx_list[1:]:
        if prev_position == 0: # 이전 축 원소가 왼쪽에 있던 경우 [prev_idx,?]
            if idx == prev_idx + 2 and idx + 1 < len(array):
                prev_position = 0
                star_len +=2
            elif idx >= prev_idx +3:
                prev_position = 1
                star_len += 2
        else: # 이전 축 원소가 오른쪽에 있던 경우 [?,prev_idx]
            if idx == prev_idx + 1 and idx + 1 < len(array) :
                prev_position = 0
                star_len += 2
            if idx >= prev_idx +2:
                prev_position = 1
                star_len += 2

        prev_idx = idx

    return star_len

def solution(a):
    if len(a) == 1:
        return 0

    elem_idx = {}
    for i,elem in enumerate(a):
        if elem_idx.get(elem):
            elem_idx[elem].append(i)
        else:
            elem_idx[elem] = [i]

    max_len = -987654321
    for elem,idx_list in elem_idx.items():
        max_len = max(max_len,find_starlen(elem,idx_list,a))
    return max_len

# print(solution([0]),0)
# print(solution([5,2,3,3,5,3]),4)
print(solution([0,3,3,0,7,2,0,2,2,0]),8)
print(solution([1, 2, 2, 1, 3]),4)
print(solution([0,0,0,2,3,4,3,5,3,1]),6)
print(solution([4, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 0, 3]),6)
# 빅데이터 테케
print(solution(tc_in),tc_out)