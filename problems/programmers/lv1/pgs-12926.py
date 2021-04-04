"""
제목 : 시저 암호

아이디어 : 아스키 코드를 이용
- 아스키 코드의 특징 : a-z,A-Z까지 1씩 증가함
    - a ~ z 사이에서 움직이는건 그냥 더해주면 됨
    - z를 넘어서는 값은 나머지 연산 처리해주면 됨
        - a = 53 z = 79 라고 하면, 79+1 -> 53이 되도록

구현 : 그냥 무식하게 하자
- for c in s:
    - c가 공백인 경우
    - c가 소문자인 경우
    - c가 대문자인 경우
"""

def solution(s, n):
    answer = ""
    for c in s :
        if c ==  ' ': answer += c
        if c >= 'a' and c <= 'z':
            answer += chr(ord(c)+n) if chr(ord(c)+n) <= 'z' else chr(ord(c)+n-26)
        if c >= 'A' and c <= 'Z':
            answer += chr(ord(c) + n) if chr(ord(c) + n) <= 'Z' else chr(ord(c) + n - 26)

    return answer

print(solution('z',3))