"""
제목 : 최적의 행렬 곱셈


전제조건 :
- 앞에서부터 계산했을 때 반드시 곱셈이 되는 입력만 들어온다
    - 즉, (a,b),(b,c),(c,d)의 형태로만 들어온다
- 주어진 행렬들의 배치 순서는 바뀌지 않는다
    - 즉 행렬 자체의 순서를 바꿔서 결과를 최소화하는 것은 생각 안해도 된다

아이디어 : 구현
- 200개 행렬의 순서를 모두 바꾸며 곱한다
-> 200! 이므로 불가능

아이디어 : 행렬 곱셈의 특성 이해
(1) 곱셈이 최소가 되는 경우의 일반식
- (a,c)*(c,d) vs (a,b) * (b,d)
    - 앞에서부터 곱하면 abc + acd
        - a와 c가 두번씩 등장
        - ac(b+d)
    - 뒤에서부터 곱하면 bcd + abd
        - b와 d가 두번씩 등장
        - bd(a+c)
    -> 2번 나오는 애들을 최소화해야 한다?
    -> 아니면 그냥 위에 나온 식을 비교하면 된다?
        - abc + acd > bcd + abd
(2) 그리디로 풀수 있는 이유의 증명
- (a,b),(b,c),(c,d)를 곱한 결과배열의 형태는 동일하다
    - 어떤 순서로 곱하든 결국 (a,d)가 됨
- (a,d)는 앞뒤로 (y,z),(z,a)와 (d,e)(e,f)와 곱해지게 됨
    - 앞부터 비교하면 ya(z+d) 또는 zd(y+a)
    - 뒤부터 비교하면 ae(d+f) 또는 df(a+e) 를 또 최소화해야 함
-> 앞 3개의 계산순서와 관꼐없이 결과배열은 동일함
-> 즉,3개씩 계산한 결과를 극소화해야 전체가 극소화 됨
-> 즉 어느배열부터 계산하느냐, 앞/뒤 어느 순서로 비교하느냐는 관계 없다!
-> 결과 : 실제로 해보니 중요하다...

구현 : list의 push pop을 통해 구현하자
(1) 최소 연산시작지점 선택하기
- 전체를 훑으며, 결과가 최소가 되는 연속된 3개의 집합을 찾는다
    - 해당 부분을 선택한다
- 해당 부분 근처의 3개를 선택해 연산한다
    - 최소가 되는 곱셈순서 결정
- 결과값을 더하고, 생성된 결과집합을 리스트에 밀어넣기

- 길이가 3 이상인 경우 위의 과정 반복
- 길이가 3 미만인 경우(즉, 2개밖에 안 남은 경우 2개를 곱하고 종료

결과 : 그리디 자체가 잘못된 풀이였다
"""
from math import inf
def solution(matrix_sizes):
    result = 0

    while len(matrix_sizes) >= 3:
        min_result = inf
        min_idx = inf
        for i in range(len(matrix_sizes)-2):
            a,b,c = matrix_sizes[i:i+3]
            left = a[0] * c[0] * (a[1] + c[1])
            right = a[1] * c[1] * (a[0] + c[0])
            if left <= min_result:
                min_result = left
                min_idx = i
            if right <= min_result:
                min_result = right
                min_idx = i

        a,b,c = matrix_sizes[min_idx:min_idx+3]
        left = a[0] * c[0] * (a[1] + c[1])
        right = a[1] * c[1] * (a[0] + c[0])

        eq = left - right
        result += right if eq > 0 else left

        matrix_sizes.pop(min_idx)
        matrix_sizes.pop(min_idx)
        matrix_sizes.pop(min_idx)
        matrix_sizes.insert(min_idx,[a[0],c[1]])

    if len(matrix_sizes) == 2:
        b = matrix_sizes.pop()
        a = matrix_sizes.pop()
        result += a[0]*a[1]*b[1]
    return result

# 테스트 케이스
# print(solution([[5,3],[3,10],[10,6]]),270)
# print(solution([[5,3],[3,10],[10,6],[6,2]]),210)
# print(solution([[99,1],[1,98],[98,99],[99,3]]),10296)
# print(solution([[5,3],[3,10],[10,6],[6,2],[2,100]]),1210)
print(solution([[5,3],[3,10],[10,6],[6,9999],[9999,2],[2,100]]))

