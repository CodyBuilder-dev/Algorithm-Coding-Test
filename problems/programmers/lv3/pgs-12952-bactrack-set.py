"""
제목 : N-Queen

아이디어 : 완전 탐색의 시간복잡도 증명
-가로 길이가 N인 체스판은 총 좌표가 N*N개
    - M개 좌표를 선택하는 경우 Combination(N*N,M)이므로, 팩토리얼 단위의 시간복잡도가 나온다
    - 가로길이가 12라고 할때, 단 5개만 뽑아도 4.8억가지의 경우의 수가 나옴
    - 12개를 뽑는 경우 1.03*10^17

- 복잡도를 줄이기 위해 1행씩 선택한다고 쳐도
    - 12*12*12*12... = 12^12 = 8.91*10^12

- 완전탐색을 좀더 스마트하게 하면 시간복잡도를 줄일 수 있다
    - 현재까지 선택된 모든 열을 저장한다
    - 이때까지 열들로 인해 선택이 불가능한 열을 제외하고, 선택이 가능한 열만 찾아낸다
    - 선택 가능한 각 열에 대해서 재귀적으로 수행한다
"""
def solution(n):
    # 이전까지의 모든 선택된 열 목록을 저장한다
    # 선택된 열목록을 조회하면서, 앞으로 선택가능한 컬럼을 선택한다
    # 선택가능한 열에 대해서만 DFS를 수행한다(가지치기)
    def recur(row, selected_col):
        if row == n: #맨 아래쪽에 도달
            return 1
        total = set(range(n))
        not_available = set()
        count = 0

        if selected_col:
            for i, col in enumerate(selected_col):
                not_available.update([col,col+(row-i),col-(row-i)])
        for available in total.difference(not_available):
            count += recur(row+1,selected_col+[available])

        return count
    return recur(0,[])

print(solution(4),2)
print(solution(12))