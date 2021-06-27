"""
제목 : 주식가격
"""
def solution(prices):
    answer = [0] * len(prices)
    stack = []

    for i,p in enumerate(prices):
        if stack and stack[-1][1] > p:
            while stack and stack[-1][1] > p:
                answer[stack[-1][0]] = i - stack[-1][0]
                stack.pop()

        stack.append((i, p))

    for s in stack:
        answer[s[0]] = len(prices) - s[0] -1
    return answer

print(solution([1, 2, 3, 2, 3]),[4,3,1,1,0])
print(solution([1,3,2,4,3,5,4]))
print(solution([1,2,3,1,3]),[4,2,1,1,0])