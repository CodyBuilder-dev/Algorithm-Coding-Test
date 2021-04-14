"""
제목 : 보석 쇼핑

아이디어 : 카카오에 설명된 풀이를 사용
"""
def solution(gems):
    original_s = set(gems)
    if len(original_s) == 1:
        return [1, 1]

    # best_answer = [123456,456789]
    interval_list = []

    left, right = 0, 0
    counter = {}
    while True:
        if len(counter) == len(original_s):  # 모든 보석이 포함되어 있음
            interval_list.append([left + 1, right])

            if counter[gems[left]] > 1:
                counter[gems[left]] -= 1
            else:
                counter.pop(gems[left])
            left += 1

        elif right >= len(gems):
            break
        else:
            counter[gems[right]] = counter.get(gems[right], 0) + 1
            right += 1

    return sorted(interval_list, key=lambda x: (x[1] - x[0], x[0]))[0]

print(solution(["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"]))
print(solution(["AA", "AB", "AC", "AA", "AC"]))
print(solution(["XYZ", "XYZ", "XYZ"]))
print(solution(["ZZZ", "YYY", "NNNN", "YYY", "BBB"]))
print(solution(["DIA", "EM", "EM", "RUB", "DIA"]))
print(solution(["A", "A", "B"]))       #5                          #10
print(solution(["AD","AA", "AB", "AC", "AA", "AC", "AD", "AB"]))
print(solution(["AD","AA", "AB", "AC", "AA", "AC", "AD", "AB", "AZ","AB","AC","AA"]))
print(solution(["AD","AA", "AB", "AC", "AA", "AC", "AC", "AD", "AB","AZ","AB","AD","AC","AA","AB","AZ","AA"]))
