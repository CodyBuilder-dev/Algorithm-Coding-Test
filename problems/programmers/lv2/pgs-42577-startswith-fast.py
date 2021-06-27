"""
제목 : 전화번호 목록

아이디어 : 길이순으로 정렬 후, 완전탐색하면서 startswith 사용

"""
def solution(phoneBook):
    phoneBook = sorted(phoneBook)

    for p1, p2 in zip(phoneBook, phoneBook[1:]):
        if p2.startswith(p1):
            return False
    return True

# 테스트 케이스
print(solution(["119", "97674223", "1195524421"]),False)
print(solution(["123", "456", "789"]),True)
print(solution(["12", "123", "1235", "567", "88"]),False)
print(solution(["1","2"]),True)
print(solution(["987987","87"]),True)
print(solution(["112","44","4544"]),True)
print(solution(["33", "11", "222", "21122", "211"]),False)
print(solution(["12","13"]),True)
