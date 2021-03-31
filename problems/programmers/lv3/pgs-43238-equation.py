"""
제목 : 입국심사

아이디어 : 구현하는 경우
- 비어있는 곳으로 가기 vs 조금 기다리기의 판단 기준을 만든다
    - 비어있는곳에 가는 조건 : 비어있는곳으로 갔을때 걸리는 시간 < 기다리는 시간 + 다른 짧은곳에 가는 시간
    - 이걸 모든 사람에게 구현한 후 시뮬레이션을 돌리면 된다.
-> 근데 조건에 사람이 10^9명이므로, 구현해서 풀지 말라는 소리임

아이디어 : 구현하지 않고 푸는 경우
- 수학문제로 바꿀 수 있다
    - x이 걸리는 심사대와 y이 걸리는 심사대가 있을 때
    - x에서 심사한 사람을 k명, y에서 심사한 사람을 l명이라 하면 k+l = n
-> 즉, k+l = n일 때 k*x + l*y가 최소가 되게 하는 수학문제를 풀면 된다

구현 : 방정식 풀이?
- 심사원이 100,000이하니꺼, 10만개만 테스트해보면 되나?
- 재귀를 100,000번 돌아야 되는데 가능한가?

"""
def find_combination_for_n(n,k,current,num_list):
    if n == 0 :
        return []
    if len(num_list) == k :
        return num_list
    for i in range(current,n) :
        yield find_combination_for_n(n-i,k,i,num_list + [i])

def solution(n, times):
    # answer = [0] *len(times)
    # return으로 테스트
    # answer = find_combination_for_n(n,len(times),0,[])

    # yield로 테스트
    for combination in find_combination_for_n(n,len(times),0,[]) :
        for i in combination :
            print(i)

    # return answer

# 테스트케이스
print(solution(6, [7, 10]))