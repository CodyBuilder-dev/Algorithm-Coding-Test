"""
제목 : 숫자 문자열과 영단어

아이디어 : replace를 사용하면 아주 쉽다
"""

def solution(s):
    s = s.replace("zero","0")\
        .replace("one","1")\
        .replace("two","2")\
        .replace("three","3")\
        .replace("four","4") \
        .replace("five", "5") \
        .replace("six", "6") \
        .replace("seven", "7") \
        .replace("eight", "8") \
        .replace("nine", "9")
    return int(s)

print(solution("one4seveneight"),1478)
print(solution("23four5six7"),234567)
print(solution("2three45sixseven"),234567)
print(solution("123"),123)