"""
구현방법
1. 0부터 무한루프를 돈다
2. 10분마다 시간은 +1, 사람수는 +10을 한다
(60분마다는 +1, 사람수는 +25)
3. 탑승가능여부를 체크한다
4. 탑승가능한 경우 시간을 환산한다
5. 
"""
waitPassenger = int(input())
liCat,javaDoc = waitPassenger + 1 , waitPassenger + 2

time = 0
totalPassenger = 0

# 탑승객 처리
while True : 
    if time%6 == 0 : totalPassenger += 25
    else :           totalPassenger += 10

    if totalPassenger >= javaDoc : break
    else :                      time += 1

# 시간 처리
# 1시간 = 6
# 1일 = 6*24 1개월 = 그때그때... 1년 = 6*24*2046
addYear,left = time // (6*24*2046) , time % (6*24*2046)
month = [1024,512,256,128,64,32,16,8,4,2]

for i,d in enumerate(month) :
    if left > d

