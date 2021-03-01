from typing import List

class Solution:
    """
    아이디어(브루트 포스)
    1. 3중 for문을 돈다
    -> 무조건 시간초과 발생
    """
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = []
        resultSet = set()

        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                for k in range(j + 1,len(nums)):
                    if nums[i]+nums[j]+nums[k] == 0:

                        # 중복 처리리
                        resultSet.add(tuple(sorted([nums[i],nums[j],nums[k]])))

        return resultSet

class Solution2:
    """
    아이디어(2개의 합으로부터 발전 -> 투 포인터)
    1. 정렬을 한다
    2. 한족을 축으로 고정시킨다
    3. 나머지에서 더해서 그 값이 되는거 찾는다
    """
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = set() # set으로 하면 리스트보단 조금 빠름
        sorted_nums = sorted(nums)
        for i in range(len(sorted_nums)):
            left = i + 1
            right = len(sorted_nums)-1
            target = sorted_nums[i] * -1
            while left < right:
                if sorted_nums[left] + sorted_nums[right] == target :
                    temp_result = (sorted_nums[i],sorted_nums[left],sorted_nums[right])
                    result.add(temp_result)
                    left +=1
                    right -= 1
                elif sorted_nums[left] + sorted_nums[right] > target :
                    right -= 1
                else :
                    left += 1

        return result

    def threeSum2(self, nums: List[int]) -> List[List[int]]:
        result = set() # set으로 하면 리스트보단 조금 빠름
        sorted_nums = sorted(nums)
        for i in range(len(sorted_nums)-1):
            # 이전에 했던 거랑 같은 수면 건너뛰기
            # 건너뛰면 3배 이상 빨라짐
            if i >0 and sorted_nums[i-1] == sorted_nums[i]: continue

            left = i + 1
            right = len(sorted_nums)-1
            target = sorted_nums[i] * -1
            while left < right:
                if sorted_nums[left] + sorted_nums[right] == target :
                    temp_result = (sorted_nums[i],sorted_nums[left],sorted_nums[right])
                    result.add(temp_result)
                    left +=1
                    right -= 1
                elif sorted_nums[left] + sorted_nums[right] > target :
                    right -= 1
                else :
                    left += 1

        return result
nums = [-1,0,1,2,-1,-4]
s = Solution2()
print(s.threeSum(nums))
