"""
제목 : 보석 쇼핑

아이디어 : 카카오에 설명된 풀이를 사용
"""
def solution(gems):
    original_s = set(gems)
    left, right = 0,0

    best_answer = [123456,456789]

    while right < len(gems) and left < len(gems):
        s = set(gems[left:right+1]) # 매번 set 연산을 반복하는게 오버헤드인듯
        if len(s) == len(original_s): # 모든 보석이 포함되어 있음
            if right - left < best_answer[1]-best_answer[0]:
                best_answer = [left+1,right+1]
            elif right - left == best_answer[1]-best_answer[0] and \
                left+1 < best_answer[0]:
                best_answer = [left+1,right+1]
            left += 1
            right = left
        else:
            right +=1

    return best_answer


# print(solution(["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"]))
print(solution(["AA", "AB", "AC", "AA", "AC"]))
print(solution(["XYZ", "XYZ", "XYZ"]))
print(solution(["ZZZ", "YYY", "NNNN", "YYY", "BBB"]))
print(solution(["DIA", "EM", "EM", "RUB", "DIA"]))
print(solution(["A", "A", "B"]))       #5                          #10
print(solution(["AD","AA", "AB", "AC", "AA", "AC", "AD", "AB"]))
print(solution(["AD","AA", "AB", "AC", "AA", "AC", "AD", "AB", "AZ","AB","AC","AA"]))
print(solution(["AD","AA", "AB", "AC", "AA", "AC", "AC", "AD", "AB","AZ","AB","AD","AC","AA","AB","AZ","AA"]))
