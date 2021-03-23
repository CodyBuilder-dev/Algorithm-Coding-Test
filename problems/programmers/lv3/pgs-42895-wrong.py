"""
문제명 : N으로 표현

아이디어 :
- N개를 써서 되느냐 안되느냐만 판단하면 됨
- 따라서 개수만 세도 되고, 단 1개만 있어도 된다
- 그렇다고 그 경우의 수를 직접 찾지는 말고, DP로 찾으면 된다

- N을 이용해 X를 만드는 방법은
(1) X - N 에서 +N을 하는 방법 --- (X - N)에 필요한 N 개수 +1
(3) X/N 에서 *N을 하는 방법 --- (X/N)에 필요한 N개수 + 1

- 예시로 생각
N = 8
X = 1000
CNT[1] = 1(N = 1) / 2 ( N!=1 )
CNT[2] =

"""


"""
아이디어 : 반대로 생각
- 어차피 1개~ 8개까지만 생각하면 되므로, 차근차근 생각해 보낟
- N = 1개일때? N = 2개일떄? N =3 개일떄?

(1) N = 1개 -> N 가능 -> [N] 저장
(2) N = 2개 -> N+N , N-N , N*N, N/N 가능 -> [N,N+N,N-N,N*N,N/N] 저장
(3) N = 3개 -> 반복
..

(4) N = 9 까지 왔는데 [] 내에 X가 없다 -> -1 반환
"""

def solution(N, number):
    answer = find_available(N,number)
    return answer

def makeNN(N,k) :
    ans = 0
    while k >= 0 :
        ans += N * 10**k-1
        k -= 1
    return ans
def find_available(N,number):
    available = [[], [N],[N+N,N-N,N*N,N//N,makeNN(N,2)]]

    for i in range(3,9):
        temp = []
        for val in available[i-2] :

        for val in available[i-1] :

        temp.append(makeNN(N,i))
        available.append(temp)
        print(available[i])
        if number in available[i] :
            return i
    print(available)
    return -1


N = 2
number = 11
print(solution(5,12))

