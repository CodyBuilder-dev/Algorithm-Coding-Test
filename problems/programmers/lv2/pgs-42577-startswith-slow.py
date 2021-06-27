"""
제목 : 전화번호 목록

아이디어 : 길이순으로 정렬 후, 완전탐색하면서 startswith 사용

"""
def solution(phone_book):
    # 길이가 긴 것부터 해야 하므로, 길이순으로 정렬한다
    phone_book = sorted(phone_book,key = lambda x:-len(x))

    # 이중 for문으로 O(N^2)으로 효율성 통과에는 실패한다
    for i in range(len(phone_book)):
        for j in range(i+1, len(phone_book)):
            if phone_book[i].startswith(phone_book[j]): return False
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
