"""
접근법 : 
1. 파이썬 배열에서 순서대로 n개 뽑기
-> Permutation
-> 이거 시간초과 남(경우의 수가 너무 많음)

2. 각 숫자들의 자리수를 비교하여 제일 큰놈을 찾자
"""

from itertools import permutations

def make_num_str(nums) :
    num_str_list=[]
    for case in permutations(nums) :
        case = map(str,case)
        num_str = ''.join(case)
        
        if num_str[0] == '0' :
            num_str = num_str[1:]
        num_str_list.append(num_str)
    return num_str_list
def check_max(num_str_list) :
    return max(num_str_list)

def solution(numbers):
    return check_max(make_num_str(numbers))
if __name__ == "__main__" :
    nums = [6,10,2]
    # make_num(nums)
    print(solution(nums))