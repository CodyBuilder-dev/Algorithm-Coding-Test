"""
유형 : LRU 알고리즘
접근방식 :
1. tuple이나 dict를 만든다
2. 입력시 dict를 탐색해서 있으면 0으로 갱신한다 O(N)
3. 없으면 자리가 있으면 추가, 없으면 제거한다
4. 제거의 기준은 가장 큰 값을 갖는 놈이다 O(N)
"""
from collections import deque

페이지 = ['척추동물', '어류', '척추동물', '무척추동물', '파충류', '척추동물', '어류', '파충류']

seat = deque()
time = 0 
for i in 페이지 :
    if i in seat :
        seat.remove(i)
        seat.append(i)
        time += 1
    else : 
        if len(seat) >= 3 :
            seat.popleft()
        seat.append(i)
        time += 60
    print(time)

minute,second = time//60, time%60
print(f"{minute}분 {second}초")