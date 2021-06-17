"""
제목 : 2개 이하로 다른 비트

아이디어 : 조건을 수식으로서 처리하면 루프가 필요없다
"""

def solution(numbers):
    answer = []

    for n in numbers:
        if n % 2 == 0: answer.append(n+1)
        else:
            mask = (n+1) - (n&(n+1))
            answer.append(n ^ (mask+mask//2))

    return answer

print(solution([2,7]))