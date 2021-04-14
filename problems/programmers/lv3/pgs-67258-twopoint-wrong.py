"""
제목 : 보석 쇼핑

아이디어 : 투포인터인건 알겠음
- 모든 보석의 종류를 파악해서 hash
- 양 끝에서 시작
    - 오른쪽부터 시작
        - 한 종류라도 제외되지 않을 때 까지 right를 왼쪽으로 축소
        - 하나라도 제외되면 right를 기록 후 left로 넘어감
    - 왼족부터 시작
        - 한 종류라도 제외되지 않을 때 까지 left를 오른쪽으로 이동
        - 하나라도 제외되면 left를 기록
    - left와 right를 중심으로 시작
        - 더 추가할 필요 없으면 그냥 반환
        - left와 right 남은 길이 중 짧은 거
"""
from collections import Counter

def solution(gems):
    c = Counter(gems)
    if len(c) == 1:
        return [1,1]

    rl, rr = 0, len(gems)-1
    # 오른쪽부터 시작해서 축소
    while True:
        if c[gems[rr]] > 1:
            c[gems[rr]] -= 1
            rr -=1
        elif c[gems[rl]] >1:
            c[gems[rl]] -= 1
            rl += 1
        else:
            break

    # 왼쪽부터 시작해서 축소
    c = Counter(gems)
    ll,lr = 0,len(gems) - 1
    while True:
        if c[gems[ll]] > 1:
            c[gems[ll]] -= 1
            ll += 1
        elif c[gems[lr]] > 1:
            c[gems[lr]] -= 1
            lr -= 1
        else:
            break




    if len(Counter(gems[ll:rr+1])) == len(c) and \
            rr-ll < min([rr-rl,lr-ll]): # 모두 포함되어 있는 경우
        return [ll+1, rr+1]
    if len(Counter(gems[rl:lr+1])) == len(c) and \
            lr-rl < min([rr-rl,lr-ll]):
        return [rl+1,lr+1]

    return [rl+1,rr+1] if rr-rl <= lr-ll else [ll+1,lr+1]


print(solution(["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"]))
print(solution(["AA", "AB", "AC", "AA", "AC"]))
print(solution(["XYZ", "XYZ", "XYZ"]))
print(solution(["ZZZ", "YYY", "NNNN", "YYY", "BBB"]))
print(solution(["DIA", "EM", "EM", "RUB", "DIA"]))
print(solution(["A", "A", "B"]))       #5                          #10
print(solution(["AD","AA", "AB", "AC", "AA", "AC", "AD", "AB"]))
print(solution(["AD","AA", "AB", "AC", "AA", "AC", "AD", "AB", "AZ","AB","AC","AA"]))
print(solution(["AD","AA", "AB", "AC", "AA", "AC", "AC", "AD", "AB","AZ","AB","AD","AC","AA","AB","AZ","AA"]))
