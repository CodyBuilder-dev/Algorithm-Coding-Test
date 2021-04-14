"""
제목 :보석 쇼핑

아이디어 :
"""
def solution(gems):
    s = set(gems)
    hash = {}
    #interval_list = [] # 리스트에 넣고 저장
    best_answer = [123456,456789]
    for i,gem in enumerate(gems):
        if gem not in hash:
            hash[gem] = 0
        hash[gem] = i

        if len(hash) ==len(s):
            temp_answer = [min(hash.values()) + 1, max(hash.values()) + 1]
            if temp_answer[1] - temp_answer[0] < best_answer[1] - best_answer[0]:
                best_answer = temp_answer
            elif temp_answer[1] - temp_answer[0] == best_answer[1] - best_answer[0] \
                    and temp_answer[0] < best_answer[0]:
                best_answer = temp_answer


    return best_answer

print(solution(["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"]))
print(solution(["AA", "AB", "AC", "AA", "AC"]))
print(solution(["XYZ", "XYZ", "XYZ"]))
print(solution(["ZZZ", "YYY", "NNNN", "YYY", "BBB"]))
print(solution(["DIA", "EM", "EM", "RUB", "DIA"]))
print(solution(["A", "A", "B"]))       #5                          #10
print(solution(["AD","AA", "AB", "AC", "AA", "AC", "AD", "AB"]))
print(solution(["AD","AA", "AB", "AC", "AA", "AC", "AD", "AB", "AZ","AB","AC","AA"]))
print(solution(["AD","AA", "AB", "AC", "AA", "AC", "AC", "AD", "AB","AZ","AB","AD","AC","AA","AB","AZ","AA"]))
