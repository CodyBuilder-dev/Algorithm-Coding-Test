"""
접근법 : 
2. 각 숫자들의 자리수를 비교하여 제일 큰놈을 찾자

구현 :
1. 첫째 자리수 비교
2. 한놈이 뛰어나오면 해당놈 선택
3. 여러놈이 나오면 두번째 자리수 비교

"""

def find_max_element(numbers):
    numbers_str = list(map(lambda x:x[0],map(str,numbers)))
    print(numbers_str)

def solution(numbers):
    return check_max(make_num_str(numbers))
if __name__ == "__main__" :
    nums = [6,10,2]
    # make_num(nums)
    find_max_element(nums)
    # print(solution(nums))