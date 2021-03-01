"""
제목 : p와 y의 개수

아이디어 : 처음부터 끝까지 loop돌면서 확인
"""
def solution(s):
    num = 0
    for c in s :
        if c == 'p' or c == 'P' :
           num += 1
        elif c == 'y' or c == 'Y' :
            num -= 1
    return not bool(num)


print(True)
print(not True)
print(~True)
print("=====")
print(False)
print(not False)
print(~False)
print("=====")
print(1)
print(not 1)
print(~1)
print("=====")
print(0)
print(not 0)
print(~0)
