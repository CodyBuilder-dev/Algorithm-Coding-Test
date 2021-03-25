"""
제목 : 집합

아이디어 :
- 집합을 실제로 구현하면, 연산을 300만번 수행하므로 시간복잡도가 매우 커진다
- 비트마스크로 1~20사이를 on/off하는 식으로 구현해야 한다
- 근데 그래도 연산의 종류가 많고 입출력이 많기 때문에,최적화가 많이 필요하다
    - input()을 최적화해야 한다
    - if-else문을 최적화해야 한다

결과 :
- 최적화 수행하니 잘 풀림
"""
from sys import stdin,stdout

def solution(M):
    bitmask = [0] * 21
    for i in range(M):
        # 입출력 최적화
        # input_string = input().split()
        input_string = stdin.readline().split()

        operation = input_string[0]
        if len(input_string) > 1:
            value = int(input_string[1])

        if operation == "add":
            bitmask[value] = 1
            continue
        if operation == "remove":
            bitmask[value] = 0
            continue
        if operation == "check":
            # print(bitmask[value])
            stdout.write(str(bitmask[value])+"\n")
            continue
        if operation == "toggle":
            bitmask[value] = 1 - bitmask[value]
            continue
        if operation == "all":
            bitmask = [1]*21
            continue
        if operation == "empty":
            bitmask = [0]*21
            continue

M = int(input())
solution(M)
