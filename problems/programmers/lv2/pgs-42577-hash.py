"""
제목 : 전화번호 목록

아이디어 : 해시 사용
- 해시의 key, value로 어떤것을 넣을것인가?
    - 문자열을 그냥 key로 넣으면 의미가 없다
    - 문자열을 앞에서부터 하나씩 늘려가며 hash에 있는지 확인한다
    - 끝까지 가도 없으면 hash에 추가한ㄷ

"""
def solution(phone_book):
    phone_book = sorted(phone_book,key = len)
    hash = {}
    for phone_number in phone_book:
        for i in range(1,len(phone_number)):
            if phone_number[:i] in hash:
                return False
        hash[phone_number] = 1
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
