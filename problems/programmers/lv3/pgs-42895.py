"""
문제명 : N으로 표현

아이디어 :
- N X개로 만들수 있는 숫자는
    - X -k  개로 만들 수 있는 숫자 에  k개로 만들 수 있는 숫자를 사칙연산 한 것

예시 :
- N 1개로 만들 수 있는 숫자
    -> N
- N 2개로 만들 수 있는 숫자
    -> 0 사칙연산 2
    -> 1 사칙연산 1
"""

def make_NN(N,k)-> int :
    ans = 0
    while k > 0 :
        ans += N * 10**(k-1)
        k -= 1
    return ans

def do_operation(set1,set2) -> list:
    ans = []
    for var1 in set1 :
        for var2 in set2 :
            lst = [var1 + var2, var1 - var2, var2 - var1,
             var1 * var2, var1 // var2, var2 // var1]
            lst = list(filter(lambda x : x != 0,lst))
            ans.extend(lst)


    return ans

def solution(N, number):
    ans = [set()]
    for i in range (1,9):
        ans.append(set([make_NN(N,i)]))

        if i == 1 :
            if number in ans[i] : return i
            else : continue

        for j in range(1,i):
            lst = do_operation(ans[j],ans[i-j])
            ans[i].update(lst)

        if number in ans[i] :
            return i
    return -1

for N in range(1,10):
    for number in range(1,32001):
        print(f"N:{N},number:{number} -> {solution(N,number)}")