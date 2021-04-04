"""
제목 : 작수와 홀수
"""
def solution(num):
    return "Odd" if not num%2 else "Even"


print(not 3%2)
print(not 4%2)

print(not 1)
print(not 0)
print(not not 0.05)
print(not not 0)

print(4%2 and "Odd" or "Even")