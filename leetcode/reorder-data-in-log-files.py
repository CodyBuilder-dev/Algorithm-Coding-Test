from typing import List

class Solution:
    """
    아이디어
    1. 문자로그는 식별자를 맨뒤로 보내서 정렬
    2. 숫자로그는 따로 뺀 후 마지막에 합치기
    """
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        digit = []
        letter = []
        for log in logs:
            if (log.split()[1].isdigit()):
                digit.append(log)
            else :
                letter.append(log)

        return sorted(letter, key=lambda s : (s.split()[1:],s.split()[0])) + digit


logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
s = Solution()
print(s.reorderLogFiles(logs))


