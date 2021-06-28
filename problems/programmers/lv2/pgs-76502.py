"""
제목 : 괄호 회전하기

아이디어 : 회전시킨 후 올바른 괄호 판정
(1) 회전은 그냥 새로운 배열을 만든다

(2)괄호판정은 스택 or 더하기
- 더하기는 해보니 괄호 종류에 따른 예외가 너무 많음
- 스택이 훨씬 편하고 쉽다
"""

def check_ok(s):
    cursor = [0, 0, 0]
    left = ['(', '{', '[']
    right = [')', '}', ']']

    for char in s:
        if char in left:
            cursor[left.index(char)] += 1
        else:
            cursor[right.index(char)] -= 1

        if list(filter(lambda x: x < 0, cursor)): return False

    if list(filter(lambda x: x != 0, cursor)): return False
    return True

def check_ok_stack(s):
    stack = []
    left = ['(', '{', '[']
    right = [')', '}', ']']

    for char in s:
        if char in left:
            stack.append(char)
        else:
            if stack and stack[-1] == left[right.index(char)]:
                stack.pop()
            else: return False

    if stack: return False
    else: return True


def rotate(s):
    return s[1:] + s[:1]

def solution(s):
    answer = 0
    for i in range(len(s)):
        s = rotate(s)
        if check_ok_stack(s):
            answer += 1

    return answer

# 테스트 케이스
print(solution("[](){}"),3)
print(solution("}]()[{"	),2)
print(solution("[)(]"),0)
print(solution("}}}"),0)
print(solution("{{{{{{{"),0)
print(solution("{"),0)
print(solution("}"),0)
print(solution("}{"),1)
print(solution("{)"),0)
print(solution("{{{}"),0)
print(solution("({)}"),0)

