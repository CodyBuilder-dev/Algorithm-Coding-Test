"""
제목 : 울타리 잘라내기

아이디어 : 분할 정복
- 문제를 반으로 나눈다
- 답은 한쪽에만(왼쪽, 오른쪽) 있는 경우, 답이 양쪽에 걸쳐있는 경우로 나눌 수 있다
    - 한쪽에만 있는 경우, 왼쪽 오른족의 맥스값을 구하면 된다
    - 양쪽에 있는 경우, 중간부터 양족으로 넓혀가며 찾는다
-> 종만북과 동일하게 구현했지만, 알고스팟 특성상 python 보정이 없으므로 시간초과가 난다
"""
from sys import stdin

def calc(heights):
    # 반환값
    if len(heights) == 1:
        return heights[0]

    mid = len(heights)//2

    # 왼쪽 또는 오른쪽 해결
    result = max(calc(heights[:mid]), calc(heights[mid:]))

    # 중간에 껴있는 부분부터 확장
    width = 2
    height = min(heights[mid-1:mid+1])
    temp_result = height*width

    left, right = mid - 1, mid
    while 0 < left or right < len(heights) - 1:
        width += 1
        if right < len(heights) - 1 and (left == 0 or heights[left-1] < heights[right+1]):
        # if right == len(heights)-1 or (left > 0 and heights[left-1] >= heights[right+1]):
            right += 1
            height = min(height, heights[right])
        else:
        # elif left == 0 or (right < len(heights)-1 and heights[left-1] <= heights[right+1]):
            left -= 1
            height = min(height, heights[left])
        temp_result = max(temp_result,width * height)

    return max(result,temp_result)

def solution():
    c = int(stdin.readline())
    for i in range(c):
        n = int(stdin.readline())
        heights = list(map(int,stdin.readline().split()))

        print(calc(heights))

def solution_t(*args):
    c = args[0]
    for i in range(c):
        n = args[1]
        heights = list(map(int,args[2].split()))

        return calc(heights)

solution()

#테스트케이스
print(solution_t(1,7,"7 1 5 9 6 7 3"))
print(solution_t(1,7,"1 4 4 4 4 1 1"))
print(solution_t(1,4,"1 8 2 2"))