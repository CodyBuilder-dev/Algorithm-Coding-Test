import datetime

def solution(a,b) :
    dayOfDate = ["MON","TUE", "WED", "THU", "FRI", "SAT", "SUN"]

    dateObj = datetime.datetime(2016,a,b)
    
    return dayOfDate[dateObj.weekday()]

a = 5
b = 24

print(solution(a,b))
