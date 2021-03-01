from typing import List


class Solution:
    """
    아이디어
    1. 내장함수를 쓰면 된다
    """
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        O(1) extra memory
        """
        # 내장 reverse 함수 자체가 in-place 함수이다.
        s.reverse()

class Solution2 :
    """
    아이디어
    1. 투포인터를 사용한다
    2. 파이썬의 쉬운 swap을 사용한다
    """
    def reverseString(selfself,s:List[str]) -> None:
        left = 0
        right = len(s) - 1

        while left < right :
            s[left], s[right] = s[right], s[left]
            left+=1
            right-=1

s = Solution2()
string = []
s.reverseString(string)
print(string)



