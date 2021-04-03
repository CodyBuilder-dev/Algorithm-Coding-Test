"""
제목 : 폰켓몬

아이디어 : 구현
- 실제로 뽑는다
- 뽑고 나서 종류를 계산한다
-> 시간복잡도 Combination(10000,2)이므로 시간복잡도 아슬아슬

아이디어 : 해시 이용
- for문을 돌면서 새로운 종류일 때마다 +1 한다
- 결과적으로 나온 종류 중에서 최대 N/2개를 뽑는다
-> 시간복잡도 O(N)
"""

def solution(nums):
    hash = {}
    for num in nums:
        if not hash.get(num) : hash[num] = 1

    return min(len(hash),len(nums)//2)


print(solution([3,1,2,3]),	2)
print(solution([3,3,3,2,2,4]),	3)
print(solution([3,3,3,2,2,2]),2)