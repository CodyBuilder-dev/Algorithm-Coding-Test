"""
제목 : 징검다리

아이디어 : 이분탐색
- '바위간의 최소 거리'를 탐색의 대상으로 삼기

구현 :
(1) N번을 제거해서 x이상을 만들 수 있는지 검사하는 방법
- 제일 작은거부터 앞에서 한칸씩 합쳐보기
-
"""
def solution(distance, rocks, n):
    rocks = sorted(rocks+[0,distance])
    diff_info = [rocks[i+1]-rocks[i] for i in range(len(rocks)-1)]

    left,right = 0, distance

    answers = []
    while left < right:
        mid = (left+right)//2
        diff_info = [rocks[i + 1] - rocks[i] for i in range(len(rocks) - 1)]
        count = 0
        i = 0
        while i < len(diff_info):
            while diff_info[i] < mid and i < len(diff_info)-1:
                diff_info[i] += diff_info.pop(i+1)
                count += 1
            i+=1

        if min(diff_info) >= mid:
            if count > n :
                right = mid
            if count < n :
                left = mid+1
            if count == n:
                answers.append(mid)
                left = mid+1
        else:
            right = mid


    # 최소값이 mid 이상으로 할 수 있는지 검사

    return max(answers)

# 테스트 케이스
# print(solution(25,[2, 14, 11, 21, 17],2),4)
# print(solution(25,[2, 14, 11, 21, 17],3))
print(solution(25,[2, 14, 11, 21, 17],4))
print(solution(10, [3, 5, 7], 2),5)
print(solution(25,[2, 14, 11, 21, 17, 24],3),4)
print(solution(10, [6,7,8,9], 3),4)
print(solution(16, [4, 8, 11], 2),8)
print(solution( distance = 34 , rocks = [5, 19, 28], n= 2 ),15)
print(solution( distance = 1234, rocks = [1, 2, 3], n = 3),1234)