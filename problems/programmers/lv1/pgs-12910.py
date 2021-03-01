"""
제목 : 나누어 떨어지는 숫자 배열
"""

def solution(arr, divisor):
    answer = [num for num in arr if num % divisor ==  0]

    if len(answer) == 0 :
        answer.append(-1)
    return sorted(answer)