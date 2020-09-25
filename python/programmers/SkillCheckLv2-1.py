"""
파이썬 배열에서 순서에 관계없이 3개 뽑기
-> Combination
"""
from itertools import combinations

def check_prime(num) :
    # 에라토스테네스의 체
    # 이거 어떻게 구현하더라..생각이 안나네
    prime = [True] * (num+1)
    for i in range(num) :
        if i == 0 : prime[i] = False
        if i == 1 : prime[i] = False
        if prime[i] :
            for j in range(i+i,num+1,i) :
                prime[j] = False
    return True if prime[num] else False
def solution(nums):
    # print(permutations(nums,3))
    cnt = 0
    for case in combinations(nums,3) :
        if check_prime(sum(case)) : 
            cnt+= 1

    # [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.

    return cnt

if __name__ =="__main__" :
    nums = [1,2,3,4]
    solution(nums)
