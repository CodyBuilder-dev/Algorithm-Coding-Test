"""
제목 : 올바른 괄호

아이디어 : 올바른 괄호의 조건을 명확히 해야 한다
- 조건을 명확히 한다
    - 열기 전에 닫으면 안된다
    - 열고 안 닫으면 안된다
    - 열고 또 여는건 괜찮다
- 처리 순서를 규정한다
    - '(' 이면 묻따없이 넣는다
    - ')' 이면 검사한다
        - 마지막 값이 '('가 아니면 무조건 실패
        - 마지막 값이 '('이면 제거

구현 : 스택을 쓰면 매우 쉽다
(1) 리스트로 스택을 쓰는 방법
(2) stack 자료형을 쓰는 방법
"""
def solution(s):
    stack = []
    for c in s:
        if c ==')' and stack and stack[-1] == '(': stack.pop(-1)
        elif c==')': return False
        else: stack.append(c)
    return False if stack else True

#테스트케이스
print(solution("()()"))
print(solution("(())()"))
print(solution(")()("))
print(solution("(()("))
