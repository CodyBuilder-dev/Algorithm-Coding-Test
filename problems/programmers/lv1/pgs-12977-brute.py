"""
제목 : 소수 만들기

아이디어 : 가능한 모든 합을 구하고 그 중에 소수를 찾는다
- 숫자 3개를 뽑아서 더한 결과를 모두 해시에 저장한다
- 3000까지의 소수를 모두 찾는다
- 결과와 소수의 교집합에서 경우의 수를 찾는닫

구현 :
- 더한 결과를 모두 해시에 저장한다
    - for문으로 구현
    - 재귀로 구현
    - combination
- 3000까지의 소수를 찾는다
    - 결국 에라토스테네스의 체
- 교집합을 만든다
    -

"""
from itertools import combinations

def eratosthenes(num:int)->dict:
    prime = dict.fromkeys(range(2,num+1),True)
    for i in range(2,int(num**0.5)+1):
        for j in range(i*i,num+1,i):
            prime[j] = False

    return prime

def solution(nums):
    MAX_NUM = 1000
    three = combinations(nums,3)
    hash_sum = dict()
    prime = eratosthenes(MAX_NUM*3)

    for case in three:
        if not hash_sum.get(sum(case)):
            hash_sum[sum(case)] = 0
        hash_sum[sum(case)] +=1

    total_count = 0
    for h in hash_sum:
        if prime[h]: total_count+= hash_sum[h]
    return total_count

#테스트 케이스
print(eratosthenes(100))
print(solution([1,2,3,4]),1)
print(solution([1,2,7,6,4]),4)
# print(dict.fromkeys(range(2,100),False))