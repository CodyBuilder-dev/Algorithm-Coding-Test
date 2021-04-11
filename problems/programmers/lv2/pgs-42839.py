"""
제목 : 소수 찾기

아이디어 : 에라토스테네스의 체
(1) 미리 에라토스테네스의 체로 소수를 찾아둔다
- 최대 7자리, 즉 10^6까지 만들어 두면 됨
- 혹은 numbers의 길이에 맞춰 만들어 두면 된다

(2) 모든 수를 만들어 가면서 소수의 개수를 찾는다
- for문을 돌면서, nPr 을 모두 체크
- 혹은 재귀로 짠다?

최적화 :
(1) 에라토스테네스의 체를 최적화하는 방법
- 검사 과정의 로직에서, 검사하는 자료구조 등에 따라 속도가 크게 다르다

(2) Permutation시 중복이 많이 일어나므로,잘 생각한다
- Permutation을 사용할 것인가?
    - set를 사용해서 중복을 없앨 것인가
    - 결과를 hash에 저장해서 중복을 없앨 것이낙
- 아예 Permutation을 대체하는 방법을 사용할 것인가?
"""
from itertools import permutations

def eratos(num: int)-> dict:
    # dict 대신 list로 구현
    # prime = dict.fromkeys(range(2,num+1),True)
    prime = [True]*(num+1)

    for i in range(2,int(num**0.5)+1):
        for j in range(i*i,num+1,i):
            prime[j] = False

    # 0, 1은 소수가 아니다
    prime[0],prime[1] = False,False

    return prime

def solution(numbers):
    prime = eratos(10**len(numbers))

    available_numbers = set()
    for i in range(1,len(numbers)+1):
        answer = set(permutations(numbers,i)) # set에 저장해 중복 제거

        # 매번 answer를 돌면서 작업을 수행하면 중복이 많이 생긴다다
        # for j in answer:
        #      v = int(''.join(j))
        #      if not hash.get(v):
        #          hash[v] = False
        #      hash[v] = prime[v]
        # 아예 가능한 숫자를 모두 미리 찾아둔다
        available_numbers.update([int(''.join(j)) for j in answer])

    # available_numbers =set(available_numbers)

    count = 0
    for num in available_numbers:
        if prime[num]: count += 1
    return count
    # return sum([hash[k] for k in hash if hash[k] ])

# 테스트 케이스
print(solution("17"))
print(solution("011"))
print(solution("9876543"))
# print(set(permutations("011")))