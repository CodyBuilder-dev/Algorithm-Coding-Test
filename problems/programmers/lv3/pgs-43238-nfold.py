"""
제목 : 입국심사

아이디어 : 구현하는 경우
- 비어있는 곳으로 가기 vs 조금 기다리기의 판단 기준을 만든다
    - 비어있는곳에 가는 조건 : 비어있는곳으로 갔을때 걸리는 시간 < 기다리는 시간 + 다른 짧은곳에 가는 시간
    - 이걸 모든 사람에게 구현한 후 시뮬레이션을 돌리면 된다.
-> 근데 조건에 사람이 10^9명이므로, 구현해서 풀지 말라는 소리임

아이디어 : 구현하지 않고 푸는 경우
-일단 N분의 1로 나눠
- 제일 큰 심사관에서 제일 작은 심사관으로 나눠줘
    - 얼마나 나눠주느냐? 제일 작은 시간 * 사람 = 제일 큰 시간 * 사람 까지
- 그 다음 심사관에서2 반복
-> 결국 O(심사관^2)이므로 통과 불가
"""

def solution(n, times):
    # 심사관마다 1/n 배분
    people = [n//len(times)]*len(times)
    namuzi = n % len(times)
    for i in range(namuzi):
        people[i] += 1

    # 제일 큰 심사관 -> 제일 작은 심사관 이관
    for i in range(len(times)-1,-1,-1) :
        for j in range(i) :


    answer = people
    return answer


print(solution(6,[7,10]))