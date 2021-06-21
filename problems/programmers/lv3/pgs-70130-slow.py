"""
제목 : 스타 수열

아이디어 : 원소의 길이가 N일 경우 모든 부분집합을 따지는 것은 2^N
-> 기각

아이디어 : 어차피 원하는 것은 스타수열의 '길이'이다
- 스타 수열이 되는 조건을 찾아내서 그 길이를 찾으면 된다
- 길이가 최대가 되려면 원소의 수가 제일 많은 놈을 축으로 삼아야 한다
- 어차피 N/2초과이면 안되니 버리고, N/2이하인 원소 중 제일 큰 친구부터 찾기
- 각 인덱스간의 거리가 무조건
-> 처리가 너무 복잡해질 듯

아이디어 :
스택을 이용해 2칸씩 비교
축이 있으면 확정
축이 없으면 대기상태
축이 2개면 하나 버리고 그 앞에 대기상태 가져옴

"""
from collections import deque
from collections import Counter
from pgs70130tc import tc_in,tc_out

def solution(a):

    max_len = -1

    for key,value in sorted(Counter(a).items(), key= lambda pair:-pair[1]):
        if value <= (max_len // 2): break
        most_common = key
        left = []
        right = deque(a)
        while right:
            middle = right.popleft()
            if middle != most_common:
                if len(left) % 2 and left[-1] == most_common:
                    left.append(middle)

                elif len(left) % 2 == 0:
                    if right and right[0] == most_common:
                        left.append(middle)

            else:
                if len(left) % 2 and left[-1] != most_common:
                    left.append(middle)
                elif len(left) % 2 == 0:
                    if right and right[0] != most_common:
                        left.append(middle)
        max_len = max(max_len,len(left))
    return max_len

print(solution([0]),0)
print(solution([5,2,3,3,5,3]),4)
print(solution([0,3,3,0,7,2,0,2,2,0]),8)
print(solution([1, 2, 2, 1, 3]),4)
print(solution([0,0,0,2,3,4,3,5,3,1]),6)
print(solution([4, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 0, 3]),6)
# 빅데이터 테케
print(solution(tc_in),tc_out)
