"""
제목 : 타겟 넘버

아이디어 :
-

구현 :
- 재귀를 이용한 DFS로 풀면 풀릴듯?
- 개수는 cnt에 저장
예외처리 :
- 일단 못만들면 가지수는 0이다
"""

cnt = 0

def dfs(numbers,target,total):
    global cnt
    if len(numbers) == 0:
        if total == target : cnt +=1
        return
    dfs(numbers[1:], target, total + numbers[0])
    dfs(numbers[1:], target, total - numbers[0])


def solution(numbers, target):
    global cnt
    dfs(numbers, target,0)
    return cnt

numbers = [1,1,1,1,1]
target = 3

print(solution(numbers,target))
