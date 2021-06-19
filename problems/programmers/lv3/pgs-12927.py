"""
제목 : 야근 지수

아이디어 :
- 남은 시간의 제곱의 합을 최소화한다
- 즉 남은 시간들이 최대한 비슷하면 되는 듯
(1) 수식으로 푼다
-> 어떤 수식으로 어떻게 풀건데? 어렵다

(2) 제일 높은 애 부터 깎아내면 된다
- 원소를 최대 힙에 집어넣는다
- 제일 큰놈을 뽑아 1 깎고 다시 집어넣는다
- 다 떨어질 때 까지 반복

구현 :
(1) 부호를 바꾸는 방법
- 모든 works의 원수는 자연수이므로 음수 씌워도 문제 없음

(2) 직접 별도의 최대 힙을 만드는 방법

"""

import heapq

def solution(n, works):
    answer = 0
    works = list(map(lambda x:-x, works))
    heap = heapq.heapify(works)
    while n:
        top = heapq.heappop(works)
        if top == 0: break
        top += 1
        heapq.heappush(works,top)
        n -=1
    return sum(map(lambda x:x**2,works))



print(solution(4,[4,3,3]),12)
print(solution(99, [2, 15, 22, 55, 55]), 580)