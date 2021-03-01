from typing import List

class Solution:
    """
    아이디어
    1. 왼쪽에서부터 쭉 훑으며 채운다
    2. 오른족에서 쭉 훑는다
    3. 둘중에 낮은거 선택
    시간복잡도
    O(N*3)
    """

    def trap(self, height: List[int]) -> int:
        left = [0]*len(height)
        right = [0]*len(height)

        leftmax = height[0]
        for i in range(len(height)):
            if leftmax < height[i]:
                leftmax = height[i]

            if leftmax <= height[i]:
                left[i] = height[i]
            else :
                left[i] = leftmax

        rightmax = height[-1]
        for i in range(len(height)-1,-1,-1):
            if rightmax < height[i]:
                rightmax = height[i]

            if rightmax <= height[i]:
                right[i] = height[i]
            else:
                right[i] = rightmax

        minheight = [min(z1,z2) for z1,z2 in zip(left,right)]
        return sum(minheight) - sum(height)

class Solution2:
    """
    아이디어 : 스택
    -> 스택이 가장 최근의 정보를 저장했다가 불러올 수 있음을 이용
    1. 높이를 스택에 넣음
    2. 높이가 높아지는 시점에 도달하면 스택에서 최근 가장 높았던 높이까지 뺌
    3. 총합 += 가로길이 * 세로길이
    """
    def trap(self, height: List[int]) -> int:
        stack =[]
        water = 0
        for i in range(len(height)):
            # 한칸 전 보다 높아짐
            while len(stack) >= 1 and height[stack[-1]] < height[i]:
                top = stack.pop()
                if len(stack) == 0: break
                garo = i - stack[-1] - 1 # 왜지
                sero = min(height[stack[-1]]-height[top],height[i]-height[top])
                water += garo*sero


            stack.append(i)

        return water


height = [0,1,0,2,1,0,1,3,2,1,2,1]
height = [4,2,0,3,2,5]
s = Solution2()
print(s.trap(height))


