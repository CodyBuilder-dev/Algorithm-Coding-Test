"""
제목 : 구명보트

아이디어 : 그리디
- 제일 무거운 사람을 뽑고 제일 가벼운 사람과 같이 태워 보낸다
- 이에 대한 수학적 증명은 https://www.notion.so/codybuilder/3114961637a54e6ab41e69db03c5b95b

결과 :
"""
from collections import deque

def solution(people, limit):
    people = sorted(people,reverse=True)
    people = deque(people)

    boats = 0
    while len(people) > 1 :
        heaviest = people.popleft()
        lightest = people.pop()
        if heaviest + lightest > limit:
            people.append(lightest)
        boats += 1
    if len(people) == 1 :
        boats +=1

    return boats


# 테스트 케이스
print(solution([20,40],100),1)
print(solution([40,40,40],100),2)
print(solution([160, 150, 140, 60, 50, 40], 200),3)
print(solution([40, 50, 60, 90],100 ),3)
print(solution([70, 50, 80, 50],100),3)
print(solution([70, 80, 50],100),3)