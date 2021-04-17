"""
제목 : 선입 선출 스케쥴링

아이디어 : 구현?
- O(10^4 * 5*10^5)이므로 불가능

아이디어 : 특정 시간에 작업가능한 코어 개수 리스트 생성
- 길이 5만
- 코어의 작업시간의 배수를 +1
    - 예시 : 0초에 3, 1초에 1, 2초에 2 3초에 2 ....
- 앞에서부터 더해가면서 n보다 커지는 시점 찾기
-> 일 5만개를 시간 1만짜리가 2명이서 하면, 5만*1만의 시간을 만들어야 함-> 실패

아이디어 : n초일 때 각 코어가 처리한 일의 개수를 재면 됨
    - 1초일때 1은 1개, 2는 0개, 3은 0개
    - 2초일때 1은 2개, 2는 1개, 3은 0개
    - 이 합이 n을 넘어서는 그 순간을 찾으면 되는데
결과  -> 느리다
"""

def solution(n, cores):
    available_cores = [[] for i in range(n+1)]

    for i, core in enumerate(cores):
        for j in range(0,n+1,core):
            available_cores[j].append(i)
    return available_cores

    sum = 0
    i = 0
    while sum < n:
        sum += len(available_cores[i])
        i+=1
    return available_cores[i][-1-(sum-n)]

print(solution(6,[1,2,3]))
print(solution(5,[4540, 6383, 8674, 2699]))