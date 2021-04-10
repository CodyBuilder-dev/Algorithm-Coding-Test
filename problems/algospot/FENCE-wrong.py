"""
제목 : 울타리 잘라내기

아이디어 : 완전 탐색
- s번째인덱스와 e번째 인덱스 사이의 판자의 최대값을 surface[s][e]에 저장
- max(surface([s][e])를 계산한다
-> 시간초과가 발생한다

아이디어 : 양쪽에서 순회하며 DP
- 왼쪽에서부터 오른쪽으로 쭉 순회한다
    - 다음에 오는게 나보다 작으면, 가로길이+1 * 다음거높이 vs 가로길이 * 지금 높이
        - 포함시키기로 결정했으면, 가로길이는 유지
        - 초기화하기로 결저앻ㅆ으면, 가로길이 초기화
    - 다음에 오는게 나보다 크면 거기서 가로길이 +1 지금 높이 vs 1* 다음거높이
        - 포함
        - 초기화
"""
def calc(heights):
    dp = [[0]*len(heights) for i in range(len(heights))]
    for i in range(len(heights)):
        for j in range(i,len(heights)):
            height = min(heights[i:j+1])
            width = j - i + 1
            dp[i][j] = width*height
    return dp

def solution():
    c = int(input())
    for i in range(c):
        n = int(input())
        heights = list(map(int,input().split()))

        print(max(map(max, calc(heights))))

def solution_t(*args):
    c = args[0]
    for i in range(c):
        n = args[1]
        heights = list(map(int,args[2].split()))
        return max(map(max, calc(heights)))

solution()

#테스트케이스
print(solution_t(1,7,"7 1 5 9 6 7 3"))