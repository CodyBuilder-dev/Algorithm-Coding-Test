"""
제목 : 울타리 잘라내기

아이디어 : 추가하기
- 상자의 길이를 오름차순으로 정렬한다
- 최초에 하나를 추가하고, 출발지와 도착지를 저장한다
- 그다음부터 하나씩 추가하되 아래의 검사를 한다
    - 출발지와 도착지가 분리된 경우
        - 일단 저장한다
    - 출발지와 도착지가 기존 출발지와 도착지 중 연결되는 경우
        - (width+1) * min(height) vs 1 * new_height 비교해서 처리
"""
def calc(heights):

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
