"""
카테고리 : 날짜 처리

아이디어 : 2016년의 n월 m일이 무슨 요일인지 알아맞추는 코드
1. 1월 1일로부터, 해당 일자까지의 일수 차이를 계산
-> 이때 윤년임을 고려해야 함
-> 각 월별 날짜는 하드코딩으로 구하기
2. 해당 일수를 7로 나눠서 나머지를 구하면 됨
"""

def solution(a, b):
    dayOfDate = ["FRI","SAT","SUN","MON","TUE","WED","THU"]
    dateOfMonth = { 1:31, 2:29, 3:31, 4:30, 5:31, 6:30,
        7:31, 8:31, 9:30, 10:31, 11:30, 12:31 }
    dateDiff = 0
    for i in range(1,a) :
        dateDiff += dateOfMonth[i]
    dateDiff += b
    dateDiff -= 1

    return dayOfDate[dateDiff % 7]

a = 5
b = 24
print(solution(a,b))