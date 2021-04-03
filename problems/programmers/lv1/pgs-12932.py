"""
제목 : 자연수 뒤집어 배열로 만들기

아이디어 : n <= 10,000,000,000인데 O(N)으로 해도 디나?
- 속지마라! 자릿수는 11자리다
"""

def solution(n):
    return list(map(int,str(n)[::-1]))

print(solution(12345))