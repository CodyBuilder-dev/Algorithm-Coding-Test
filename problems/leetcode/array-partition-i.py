from typing import List


class Solution:
    """
    아이디어 : 그리디한 접근
    1. 그냥 밑에서부터 두개씩 자르면 되는거 아냐
    """
    def arrayPairSum(self, nums: List[int]) -> int:
        sum = 0
        sorted_nums = sorted(nums)
        for i in range(0,len(nums),2):
            sum += sorted_nums[i]
        return sum

    """
    아이디어 :
    1. 슬라이싱을 이용해 코드 간결화
    """
    def arrayPairSum2(self, nums: List[int]) -> int:
        return sum(sorted(nums)[::2]) # 슬라이싱이므로, for문보다는 비교적 성능이 좋다

nums = [6,2,6,5,1,2]
s =Solution()
print(s.arrayPairSum(nums))
