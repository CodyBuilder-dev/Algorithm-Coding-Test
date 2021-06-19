"""
제목 : 외벽 점검

아이디어 : 사람을 배치해 가면서 몇명이 최소인지 직접 찾는다
-> 딱봐도 엄청나게 많은 경우의 수가 필요해 보인다...
-> 기각

아이디어 :
- 어차피 친구의 수는 최대 8명이고, 구하는 것은 사람의 수이다
-> 즉, 굳이 모든 경우의 수를 찾을 필요 없이, n명일 때 되는지 안 되는지만 확인하면 된다

- 점들을 n개의 구간으로 나누고, 구간마다 1명씩 사람을 배정해 검사하면 된다
- 특정 사람이 특정 구간을 검사할 수 있는지 없는지는 아래와 같이 구한다
    - 구간 내의 모든 점을 이은 최단 거리를 구한다
    - 그 최단거리를 현재 검사할 수 있는 사람의 속도와 비교한다
    - 최단거리가 속도보다 짧으면 검사 가능, 최단거리가 속도보다 길면 검사 불가능

구현 :
(1) weak를 n구간으로 나눈다
    - 구간 분할은, 구간의 시작 index를 추출하는 것으로 구현한다
    - n개의 구간이면 15Cn을 이용한다
(2) 해당 구간의 최단길이를 구한다
    - 원의 둘레 - (해당 구간의 점들간 거리 중 가장 긴 것) 으로 구할 수 있다
(3) 각자가 구간을 해결할 수 있는지 파악한다
    - 제일 짧은 구간을 제일 느린 사람이, 제일 긴 구간을 제일 빠른 사람에게 배정하는 것이 좋다
    - 즉, 구간 길이와 사람 속도를 둘다 오름차순 정렬해 1개씩 비교한다
(4) 해결이 될 경우, 해당 구간 수가 곧 사람의 수다 8명 다 써도 안되면 그냥 -1 반환
(5) 해결이 안될 경우, 구간을 하나 더 나눠서 n+1구간으로 (1)~(3)을 반복한다.
    - 8명이 넘어도 안되면 -1을 반환한다

(Case 1)
1명이 돌수 있는가?
    -> 모든것을 다 더했을 경우의 가장 짧은 경로 찾기
    -> [1 5 6 10] -> [4 1 4 3] -> 12 - 4 = 8 > 4이므로 안된다
2명이 돌수 잇는가?
    -> 점을 2구간으로 나눈다 -> 각 집합의 가장 짧은 경로 찾기
    -> [1 / 5 6 10],[5 / 1 6 10],[1 5 / 6 10],[5 6 / 1 10] ...
    -> 저 중에서 [5 6 / 1 10]의 케이스의 경우 탐색 가능


(Case 2)
1명이 돌수 있는가
    -> [1 3 4 9 10 ]  -> [ 2 1 5 1 3 ] -> 12 - 5 = 7 <= 7이므로 탐색 가능
"""
from itertools import combinations


def solution(n, weak, dist):
    dist = sorted(dist)

    # 1명,2명,3명... 순으로 다 돌수 있는지 체크
    for people_no in range(1,len(dist)+1):
        gugan_cases = list(combinations(range(len(weak)),people_no))

        for case in gugan_cases:
            gugan = []
            for j in range(len(case)):
                if j == len(case) -1:
                    gugan.append(weak[:case[0]]+weak[case[j]:])
                else:
                    gugan.append(weak[case[j]:case[j+1]])


            gugan_length = []
            for g in gugan:
                gugan_length.append(n - max([y-x for x,y in zip(g, g[1:]+[n+g[0]])]))

            is_avail = True
            for x,y in zip(sorted(gugan_length),dist[-len(gugan_length):]):
                if x>y: is_avail = False

            if is_avail: return people_no

    return -1

print(solution(12,[1, 5, 6, 10],[1, 2, 3, 4]))
print(solution(12,	[1, 3, 4, 9, 10],	[3, 5, 7]))
