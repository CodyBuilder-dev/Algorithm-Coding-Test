import re

class Solution1:
    """
    아이디어
    1. 우선 전처리를 통해 소문자만 제외하고 모두 제거한다
    2. 결과물을 뒤집어 비교한다
    """
    def isPalindrome(self, s: str) -> bool:
        clist = []
        for c in s :
            # python if-else보다 C기반 isalnum()이 더 빠르다
            if c.isalnum() :clist.append(c.lower())

        return True if clist == clist[-1::-1] else False

    def isPalindrome2(self, s: str) -> bool:
        # 반복문을 isalnum으로 아무리 빨리 돌려도 정규표현식보다는 못하다
        s = re.sub("[^a-z0-9]","",s.lower())

        # pop 비교보다는 슬라이싱이 훨씬 빠르다
        return True if s == s[::-1] else False

solution1 = Solution1()
print("Solution 1")
print(solution1.isPalindrome("P0"))

from collections import deque

class Solution2 :
    """
    아이디어
    1. 1번 풀이와 동일한데 자료구조를 deque로 써본다
    """
    def isPalindrome(self,s: str)-> bool :
        clist = deque()
        for c in s :
            if c.isalnum(): clist.append(c.lower())

        while len(clist) > 1:
            if clist.popleft() != clist.pop():
                return False

        return True


solution2 = Solution2()
print("Solution 2")
print(solution2.isPalindrome("P0P"))


