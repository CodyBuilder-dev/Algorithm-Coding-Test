"""
제목 : 약수의 개수와 덧셈

아이디어 : 그냥 구현하면 된다
(1) 특정 수의 약수개수를 찾아주는 함수를 만든다
(2) 범위내에 대해서 반복한다
"""
def find_divisor(num):
    answer = []
    for i in range(1,num):
        if not num%i: answer.append(i)

    return answer

def solution(left, right):
    return sum([-num if len(find_divisor(num)) % 2 else num for num in range(left,right+1)])