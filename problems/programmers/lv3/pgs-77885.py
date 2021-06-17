"""
제목 : 2개 이하로 다른 비트

아이디어 : 정말 무식한 풀이법 = 1씩 늘리며 찾기
- O(10^5 * k)이므로 한 숫자에 대해 10^4번만 비교해 봐도 바로 초과남
-> 기각

아이디어 : 규칙을 찾아서 하드코딩?
10 -> 11
0111 -> 1011
1011 -> 1101
100 -> 101
1100 -> 1101
(1) 00이 있으면 우선 01로 바꾼다
(2) 01이 있으면 우선 10으로 바꾼다
(3) 10이 있으면...
-> 검증할 수 없는 아이디어, 수많은 반례, 지저분한 코드
-> 기각

아이디어 : 11을 Shift하면서 XOR하면 정확히 2개씩 뒤집힌다
"""

def solution(numbers):
    answer = []

    for n in numbers:
        if n ^ (3 >> 1) > n:
            answer.append(n ^ (3 >> 1))
            continue
        i = 0
        while True:
            if n ^ (3 << i) > n:
                answer.append(n ^ (3 << i))
                break
            i += 1

    return answer

print(solution([2,7]))