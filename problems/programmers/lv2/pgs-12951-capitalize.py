"""
제목 : JadenCase 문자열 만들기

아이디어 :
(1) split(" ")으로 잘라낸다
- split()과의 차이점은 공백이 여러개인 경우 해당 공백들도 list에 넣는다는 것
(2) capitalize를 이용해 대문자화한다
"""


def solution(s):
    return ' '.join([word.capitalize() for word in s.split(" ")])


print(solution("3people unFollowed me"))
print(solution("for the last week"))
print(solution("hide  on    the           space"))