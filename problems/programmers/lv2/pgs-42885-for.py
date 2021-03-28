"""
제목 : 구명보트

아이디어 :
(1)완탐으로 풀면 O(N^2)로 정확도는 해결된다
- 가장 무거운 사람을 태운다
- 그 사람과 맞는 사람을 찾는다
    - 다음으로 무거운 사람을 찾거나
    - 제일 가벼운 사람을 찾거나
- 상식적으로, 다음으로 무거운 사람을 태우는게 맞는데 왜 제일 가벼운 사람을 태워도 될까?
    - 수학적으로 증명 가능
    - 자세한 설명은
(2) 조금만 생각해서 가지수를 줄일 수 있다
- 맨 앞의 사람이 50kg 미만이면, 그 뒤로는 어떻게 태워도 무조건 2명이 탄다

결과 :
- 최적화를 나름 했는데도 통하지 않음
"""
def solution(people, limit):
    people = sorted(people,reverse=True)
    rescued = [False]*len(people)
    boats = 0

    for i in range(len(people)):
        if not rescued[i] :
            for j in range(i+1,len(people)):
                if not rescued[j] and people[i] + people[j] <= limit :
                    rescued[i],rescued[j] = True,True
                    break
            boats += 1
            rescued[i] = True
        # if not rescued[i] and people[i] <= 50:
        #     boats += (rescued[i:].count(False)+1)//2
        #     break
    return boats


# 테스트 케이스
print(solution([20,40],100),1)
print(solution([40,40,40],100),2)
print(solution([160, 150, 140, 60, 50, 40], 200),3)
print(solution([40, 50, 60, 90],100 ),3)
print(solution([70, 50, 80, 50],100),3)
print(solution([70, 80, 50],100),3)