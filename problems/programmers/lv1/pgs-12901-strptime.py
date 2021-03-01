"""
카테고리 : 날짜 처리 

아이디어 : 날짜 문자열을 만든 후, 이를 datetime Obj로 만들어 처리한다

문제점 : strptime(문자열,format)으로 문자열을 파싱하는 속도는
datetime(year,month,date)로 직접 생성하는것보다 훨씬 느리다(100배 이상)

"""
import datetime

def solution(a,b) :
    dayOfDate = ["MON","TUE", "WED", "THU", "FRI", "SAT", "SUN"]
    dateStr = f"2016/{a}/{b}"
    dateObj = datetime.datetime.strptime(dateStr,"%Y/%m/%d")
    
    return dayOfDate[dateObj.weekday()]

a = 5
b = 24

print(solution(a,b))

