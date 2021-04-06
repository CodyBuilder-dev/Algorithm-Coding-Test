"""
제목 : 짝지어 제거하기

아이디어 : 스택 사용
- (1) 선형 구조에서 (2) 이웃한 중복된 부분 (3) 제거하는데에는
-> 스택이 최고다
"""
def solution(s):
    stack = []
    for c in s:
        if stack and stack[-1] == c: stack.pop(-1)
        else: stack.append(c)

    return 0 if stack else 1

# 테스트 케이스
print(solution("baabaa"))
print(solution("cdcd"))