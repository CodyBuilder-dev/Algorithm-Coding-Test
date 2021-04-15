"""
제목 : 징검다리

아이디어 : 어차피 길이는 고정되어 있다
- 길이, (바위1,바위2)저장
- 우선순위 큐에 넣음
- 제일 길이가 짧은 놈 선택
    - 그 옆에있는놈과 합치면 되는데, 양쪽 둘 중 작은놈을 선택
    -

구현 :
(1)그냥 dict를 정렬하자...
-> 생각해보니 거리가 벌어졌을 떄 찾기 어렴다
(2) 리스트에 정보를 저장하자

(3) 링크드리스트를 구현하자

(4) 그냥 리스트를 그대로 쓰고 pop하자
"""

import heapq
from queue import PriorityQueue
def solution(distance, rocks, n):


    rocks = sorted(rocks+[0,distance])
    diff_info = [rocks[i+1]-rocks[i] for i in range(len(rocks)-1)]

    count = 0
    while count < n:
        min_idx = diff_info.index(min(diff_info))
        if min_idx == 0: # 시작점인 경우
            diff_info[min_idx] += diff_info.pop(min_idx+1)
            rocks.pop(min_idx+1)

        elif min_idx == len(diff_info)-1:
            diff_info[min_idx-1] += diff_info.pop(min_idx)
            rocks.pop(min_idx)
        else:
            if diff_info[min_idx-1] < diff_info[min_idx+1]:
                diff_info[min_idx-1] += diff_info.pop(min_idx)
                rocks.pop(min_idx)
            else:
                diff_info[min_idx] += diff_info.pop(min_idx + 1)
                rocks.pop(min_idx + 1)
        count+=1

    print(diff_info)
    return min(diff_info)

print(solution(25,[2, 14, 11, 21, 17],2))
print(solution(25,[2, 14, 11, 21, 17],3))
print(solution(25,[2, 14, 11, 21, 17],4))
print(solution(10, [3, 5, 7], 2),5)
print(solution(25,[2, 14, 11, 21, 17, 24],3),4)
print(solution(10, [6,7,8,9], 3),4)
print(solution(16, [4, 8, 11], 2),8)