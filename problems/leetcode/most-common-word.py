import re
from typing import List
from collections import Counter

class Solution:
    """
    아이디어
    1. 개수 셀때부터 제외하고 세기
    """
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        s = re.sub("[!?',;.]",' ',paragraph.lower())
        slist = s.split()
        scount = {}
        for word in slist :
            if word not in banned :
                if scount.get(word) : scount[word] +=1
                else : scount[word] = 1
        return max(scount,key = lambda x : scount[x])

    """
    아이디어
    1. 일단 다 넣고나서 pop 방식으로 구현
    """
    def mostCommonWord2(self, paragraph: str, banned: List[str]) -> str:
        s = re.sub("[!?',;.]",' ',paragraph.lower())
        slist = s.split()

        freq = dict(Counter(slist))
        for key in banned :
            if key in freq :
                freq.pop(key,None) # pop을 반복하면 필연적으로 느려지는 듯
        return max(freq, key = lambda x: freq[x])

    """
    아이디어
    1. 전처리를 리스트 컴프리헨션을 이용해 좀더 깔끔하게 처리 
    2. 개수 세기는 Counter의 most_common 사용
    """
    def mostCommonWord3(self, paragraph: str, banned: List[str]) -> str:
        words = [word for word in re.sub("[^\w]"," ",paragraph).lower().split()
                    if word not in banned]

        return Counter(words).most_common(1)[0][0]

    """
    아이디어
    1. banned를 hash map으로 만들어 검색시 O(1)로 개선
    """
    def mostCommonWord4(self, paragraph: str, banned: List[str]) -> str:
        banned = dict.fromkeys(banned,0)
        words = [word for word in re.sub("[^\w]"," ",paragraph).lower().split()
                    if word not in banned]

        return Counter(words).most_common(1)[0][0]
s = Solution()
print(s.mostCommonWord3("Bob hit a ball, the hit BALL flew far after it was hit.",["was"]))