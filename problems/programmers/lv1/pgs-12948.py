"""
제목 : 핸드폰 번호 가리기
"""
def solution(phone_number):
    return "*"*(len(phone_number)-4) + phone_number[-4:]


phone_number = "01033334444"
phone_number = "027778888"
phone_number = "1234"
print(solution(phone_number))