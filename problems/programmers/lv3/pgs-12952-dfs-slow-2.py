"""
제목 : N-Queen

아이디어 : 완전 탐색의 시간복잡도 증명
-가로 길이가 N인 체스판은 총 좌표가 N*N개
    - M개 좌표를 선택하는 경우 Combination(N*N,M)이므로, 팩토리얼 단위의 시간복잡도가 나온다
    - 가로길이가 12라고 할때, 단 5개만 뽑아도 4.8억가지의 경우의 수가 나옴
    - 12개를 뽑는 경우 1.03*10^17

- 복잡도를 줄이기 위해 1행씩 선택한다고 쳐도
    - 12*12*12*12... = 12^12 = 8.91*10^12

구현 : 그럼에도 불구하고 DFS로 구현해보자
"""
def is_available(q1,q2):
    if q1[0] == q2[0]: return False # 가로줄
    if q1[1] == q2[1]: return False # 세로줄
    if q1[0]+q1[1] == q2[0]+q2[1]: return False # 우상향 대각선
    if q1[0]-q1[1] == q2[0]-q2[1]: return False # 우하향 대각선

    return True


def solution(n):
    # 제약조건에 의해, 사실상 퀸은 한 가로줄에 하나씩 놓아야 한다
    # 즉, 가로줄의 길이와 퀸의 개수를 같다고 판단하고 로직을 짜도 좋다
    queens =[]
    while len(queens) < n:
        for i in range(n):
            for j in range(n):
                for q in queens:
                    if not is_available([i,j],q): continue
                    else: queens.append([i,j])

    return len(queens)

print(solution(4),2)
print(solution(12))