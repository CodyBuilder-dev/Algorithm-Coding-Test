"""
제목 : 스티커 모으기

아이디어 : 완탐?
- 10^5^2이므로 불가

아이디어 : 재귀
- 연속된 2개를 시작으로 재귀를 돈다
    - 왼쪽 놈을 뽑는 경우에 대해 재귀
    - 오른쪽 놈을 뽑는 경우에 대해 재귀
- 재귀 돌 때는, visited를 만들어 돌린다
    - 반환값은 선택 가능한 max값
    - 기저경우는 len == 1일때 그대로 반환
    - 현재 선택된 값 + max(return값들)

아이디어 : 생각의 방향 전환
- 더 많이 더하려 하지 말고, 더 적게 손해보는 쪽을 선택한다?
- 각 수마다 선택했을 경우 날리는 비용을 계산한다
    - 비용이 가장 작은 놈을 뽑고 재귀
    - 비용이 동일한 놈이 있는 경우 각 경우에 대해 모두 재귀를 돈다
- 비용이 동일한 경우, 재귀로 완탐?
"""
def recur(sticker,visited):
    if sum(visited) == len(sticker):
        return 0

    if sum(visited) == len(sticker) - 1:
        idx = visited.index(False)
        return sticker[idx]

    result = 0

    left = visited.index(False)
    visited[left-1], visited[left],visited[(left+1)%len(sticker)] = True,True,True
    result = max(result,sticker[left] + recur(sticker,visited))
    visited[(left+1)%len(sticker)] = False

    left = (left + 1) % len(sticker)
    visited[left - 1], visited[left], visited[(left + 1) % len(sticker)] = True, True, True
    result = max(result, sticker[left] + recur(sticker, visited))
    visited[(left+1)%len(sticker)] = False

    left = (left + 1) % len(sticker)
    visited[left - 1], visited[left], visited[(left + 1) % len(sticker)] = True, True, True
    result = max(result, sticker[left] + recur(sticker, visited))
    for i in range(-3,2):
        visited[(left+i)%len(sticker)] = False

    return result

def solution(sticker):
    visited = [False]*len(sticker)
    answer = recur(sticker,visited)

    return answer

print(solution([14, 6, 5, 11, 3, 9, 2, 10]))
# print(solution([1, 3, 2, 5, 4]))
# print(solution([2]))
# print(solution([2,4]))
# print(solution([4,5,6]))
# print([True,False,False].index(False))
