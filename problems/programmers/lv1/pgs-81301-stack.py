"""
제목 : 숫자 문자열과 영단어

아이디어 : stack을 사용하면, 대규모 문자열에서 조금 더 효율적이지 않을까?
"""

def solution(s):
    hash = {"zero":"0",
            "one": "1",
            "two": "2",
            "three": "3",
            "four": "4",
            "five": "5",
            "six": "6",
            "seven": "7",
            "eight": "8",
            "nine": "9"
            }
    stack = []
    answer = []
    for c in s:

        if c.isdigit():
            answer.append(c)
        else:
            stack.append(c)
            if ''.join(stack) in hash:
                answer.append(hash[''.join(stack)])
                stack = []

    return int(''.join(answer))

print(solution("one4seveneight"),1478)
print(solution("23four5six7"),234567)
print(solution("2three45sixseven"),234567)
print(solution("123"),123)