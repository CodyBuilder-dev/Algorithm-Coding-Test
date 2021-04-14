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
    original_c = Counter(gems)
    if len(original_c) == 1:
        return [1,1]

    interval_list = []
    # 가장 왼족에 있는 right 포인터 위치 찾기

    right = len(gems)-1
    c = Counter(gems)
    while True:
        if c[gems[right]] > 1:
            c[gems[right]] -= 1
            right -= 1
        else:
            break

    while right < len(gems):
        left = 0
        c = Counter(gems[:right+1])
        # 왼쪽부터 시작해서 축소
        while True:
            if c[gems[left]] > 1:
                c[gems[left]] -= 1
                left += 1
            else:
                break

        interval_list.append([left+1, right+1])
        right += 1

    return sorted(interval_list, key= lambda x:(x[1]-x[0], x[0]))[0]

print(solution(["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"]))
print(solution(["AA", "AB", "AC", "AA", "AC"]))
print(solution(["XYZ", "XYZ", "XYZ"]))
print(solution(["ZZZ", "YYY", "NNNN", "YYY", "BBB"]))
print(solution(["DIA", "EM", "EM", "RUB", "DIA"]))
print(solution(["A", "A", "B"]))       #5                          #10
print(solution(["AD","AA", "AB", "AC", "AA", "AC", "AD", "AB"]))
print(solution(["AD","AA", "AB", "AC", "AA", "AC", "AD", "AB", "AZ","AB","AC","AA"]))
print(solution(["AD","AA", "AB", "AC", "AA", "AC", "AC", "AD", "AB","AZ","AB","AD","AC","AA","AB","AZ","AA"]))
