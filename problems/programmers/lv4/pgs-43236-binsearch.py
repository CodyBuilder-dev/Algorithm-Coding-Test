"""
제목 : 징검다리

아이디어 : 어차피 길이는 고정되어 있다
- 길이, (바위1,바위2)저장
- 우선순위 큐에 넣음
- 제일 길이가 짧은 놈 선택
    - 그 옆에있는놈과 합치면 되는데, 양쪽 둘 중 작은놈을 선택
    -

구현 : 재귀를 쓸 수 있을지도?
-> 결과는 시간 초과
-> 백트래킹 써야 되나?
"""
def recur(rocks,diff_info,n):
    if not n:
        return min(diff_info)

    min_idx = diff_info.index(min(diff_info))

    answer = []
    if min_idx == 0:  # 시작점인 경우
        diff_info[min_idx] += diff_info.pop(min_idx + 1)
        rocks.pop(min_idx + 1)

        answer.append(recur(rocks,diff_info,n-1))

    elif min_idx == len(diff_info) - 1:  # 마지막인 경우
        diff_info[min_idx - 1] += diff_info.pop(min_idx)
        rocks.pop(min_idx)

        answer.append(recur(rocks,diff_info,n-1))
    else:
        diff_info2 =  diff_info.copy()
        rocks2 = rocks.copy()

        diff_info2[min_idx - 1] += diff_info2.pop(min_idx)
        rocks2.pop(min_idx)
        answer.append(recur(rocks2, diff_info2, n - 1))

        diff_info[min_idx] += diff_info.pop(min_idx + 1)
        rocks.pop(min_idx + 1)
        answer.append(recur(rocks, diff_info, n - 1))
    return max(answer)

def solution(distance, rocks, n):
    rocks = sorted(rocks+[0,distance])
    diff_info = [rocks[i+1]-rocks[i] for i in range(len(rocks)-1)]

    return recur(rocks,diff_info,n)

# 테스트 케이스
print(solution(25,[2, 14, 11, 21, 17],2))
print(solution(25,[2, 14, 11, 21, 17],3))
print(solution(25,[2, 14, 11, 21, 17],4))
print(solution(10, [3, 5, 7], 2),5)
print(solution(25,[2, 14, 11, 21, 17, 24],3),4)
print(solution(10, [6,7,8,9], 3),4)
print(solution(16, [4, 8, 11], 2),8)
print(solution( distance = 34 , rocks = [5, 19, 28], n= 2 ),15)
print(solution( distance = 1234, rocks = [1, 2, 3], n = 3),1234)