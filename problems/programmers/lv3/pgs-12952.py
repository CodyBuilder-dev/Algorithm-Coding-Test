"""
제목 : N-Queen

아이디어 : 완전 탐색의 시간복잡도 증명
-가로 길이가 N인 체스판은
    - 총 좌표가 N*N개
    - M개 좌표를 선택하는 경우 Combination(N*N,M)이므로, 팩토리얼 단위의 시간복잡도가 나온다
- 가로길이가 12라고 할때, 단 5개만 뽑아도 4.8억가지의 경우의 수가 나옴

아이디어 : 백 트래킹
- 퀸을 놓는다
- 다른 퀸이 잡히는 지 체크한다
    - 이때, 멍청하게 모든 좌표를 검사하면 느리다 O(N*N)
    - 다른 퀸의 목록을 저장해 두고, 그 목록을 검사해라 O(M)
- 검사 방법은, x값이 동일하거나 y값이 동일하거나 대각선 검사
    - 대각선 검사는 행/열의 합/차를 이용해 검사

구현 : 스택
- 퀸의 목록을 별도로 저장한다고 하자
- DFS 방식으로 저장했다가 안되면 다 걷어내야 하므로, 스택을 쓰는게 제일 효율적이다

수도코드 :
- 아무데나 놓는다
    - 다음 되는 곳에 놓는다
    - 더 놓을 수 없는 곳 까지 돈다
    - 총 놓은 개수를 체크한다
        - n개 미만이면 전부 제거한다
        - n개면 해당 결과를 저장하고 처음부터 다시 한다
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

print(solution(4))
print(solution(12))