from math import gcd

def solution(num):
	lcm = num[0]
	for i in num:
		lcm = i*lcm // gcd(i,lcm)

	return lcm

print(solution([2,6,8,14]),168)
print(solution([2,3,5]),30)
print(solution([3, 4, 9, 16]), 144)
