"""
아이디어 :
- 재귀를 통해 풀자
- dfs(N,number,i)는
    - dfs(N, number -N, i+1)
    - dfs(N, number // N, i+1)
    - dfs(N , number * N, i+1)
    - dfs(N, number + N, i+1)
    ...
    계속 재귀적으로 쪼개다 보면
    i(count) = 8 이 되거나
    그 전에 끝난다
"""
maxima = 987654321
minima = 987654321

def makeNN(N,k) :
    ans = 0
    while k > 0 :
        ans += N * 10**(k-1)
        k -= 1
    return ans

def dfs(N,number,i):
    global minima, maxima
    # print(N,number,i)
    if  number == makeNN(N,i):
        return i
    if i > 8 :
        return maxima
    minima = min(minima, dfs(N, number + N, i + 1))
    if number - N > 0:
        minima = min(minima, dfs(N, number - N, i + 1))
    minima = min(minima, dfs(N, number * N, i + 1))
    minima = min(minima, dfs(N, number // N, i + 1))
    return minima

def solution(N,number):
    dfs(N,number,1)
    return minima


# print (makeNN(5,0))
N = 5
number = 12
print(solution(N,number))