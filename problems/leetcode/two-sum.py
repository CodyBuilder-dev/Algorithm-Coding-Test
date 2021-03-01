from typing import List

class Solution:
    """
    아이디어 : 브루트 포스
    1. 단순히 이중 for문으로 돌면서 더하기
    """
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)) :
            for j in range(i+1,len(nums)) :
                if nums[i] + nums[j] == target :
                    return [i,j]
    """
    아이디어 : 브루트 포스
    1. 각 값에서 target을 뺀다
    2. 나온 결과의 절대값이 존재하는지 in으로 찾는다
    """
    def twoSum2(self, nums: List[int], target: int) -> List[int]:
        for i,num in enumerate(nums):
            if (target-num) in nums[i+1:] : # 파이썬 반복문보단 in이 빠름
                return [i,nums[i+1:].index(target-num)+(i+1)]

    """
    아이디어
    1. in을 hash map으로 만들어 검색 속도를 O(1)로 개선
    -> 문제점 [3,3]같은 경우는 적용 불가
    """
    def twoSum3(self, nums: List[int], target: int) -> List[int]:
        numdict = {num:i for i,num in enumerate(nums)}
        for num in numdict :
            if numdict.get(target-num) : return numdict[num], numdict[target-num]
nums = [3,2,4]
target = 6

s = Solution()
print(s.twoSum3(nums,target))
