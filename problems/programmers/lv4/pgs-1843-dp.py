"""
제목 : 사칙연산

아이디어 : DP
- 특정 구간의 최대값과 최소값을 구한다
    - start부터 end까지 연산한 결과의 최대값을 maxima[start][end]에 저장
    - start부터 end까지 연산한 결과의 최소값을 minima[start][end]에 저장
- 구간길이를 점차 늘려 나간다
    - 2개일 때는 [0][1],  [1][2], ...
    - 3개일 때는, max([i] + [i+1][i+2], [i][i+1] + [i+2]
    - 4개일 때는, max([


"""
from math import inf

def calc_eq(numbers,ops,s,e):
    if e == s:
        return eval(numbers[s])

    eq = ""
    for i in range(s,e):
        eq += numbers[i]
        eq += ops[i]
    eq += numbers[i+1]
    return eval(eq)


def solution(arr):
    # 숫자와 연산자 분리
    numbers = []
    ops = []

    for c in arr:
        if c.isdigit():
            numbers.append(c)
        else:
            ops.append(c)

    # maxima, minima 저장
    n = len(numbers)
    maxima = [[-inf]*n for _ in range(n)]
    minima = [[inf]*n for _ in range(n)]
    for i in range(n):
        maxima[i][i] = int(numbers[i])
        minima[i][i] = int(numbers[i])

    for i in range(n-1):
        maxima[i][i + 1] = eval(numbers[i] + ops[i] + numbers[i + 1])
        minima[i][i + 1] = eval(numbers[i] + ops[i] + numbers[i + 1])

    for l in range(3,n+1):
        for i in range(n-l+1):
            local_max = -inf
            local_min = inf
            for j in range(l-1):
                if ops[i+j] == "+":
                    temp_max = maxima[i][i+j] + maxima[i+j+1][i+l - 1]
                    temp_min = minima[i][i+j] + minima[i+j+1][i+l - 1]
                else:
                    temp_max = maxima[i][i + j] - minima[i + j + 1][i + l - 1]
                    temp_min = minima[i][i + j] - maxima[i + j + 1][i + l - 1]
                local_max = temp_max if temp_max > local_max else local_max
                local_min = temp_min if temp_min < local_min else local_min

            maxima[i][i+l-1] = local_max
            minima[i][i+l-1] = local_min

    return maxima[0][n-1]


print(solution(["1", "-", "3", "+", "5", "-", "8"]))
print(solution(["1", "-", "3", "+", "5", "-", "8", "-", "7"]),1)
print(solution(["5", "-", "3", "+", "1", "+", "2", "-", "4"]))
print(solution(["10","-","5","+","7","-","100"]))
print(solution(["5","+","999","-","1000","-","5"]))
print(solution(["5","-","999","-","1000","-","5"]))
