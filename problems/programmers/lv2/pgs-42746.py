
"""

제목 : 가장 큰 수



아이디어 : 그냥 맨 앞자리 숫자 기반으로 정렬한 후 합치면?

    - 첫자리가 큰 순

    - 첫자리가 동일하면, 길이가 짧은 것 우선

    - 둘째자리가 있으면 높은 순



구현 : 문자열을 맨 앞자리를 숫자로 인식해 비교한다

"""

# 파이썬에서 정렬의 key로 사용할 수 있는 함수는, 하나의 인자를 받아 특정한 값으로 만들어서 반환 가능한 함수이다.

# sorted함수는, 그 반환된 결과값(여러개일 경우 튜플)을 기준으로 정렬한다

def solution(numbers):

    if sum(numbers) == 0 :

        return "0"

    answer = list(map(str,numbers))

    # answer = sorted(answer,key = lambda x:-1*int(x[0]),-1*int(x[1]),-1*int(x[2]),-1*int(x[3]),len(x))

    answer = sorted(answer,key = lambda x:(x[0],x + x[0]*(4-len(x))))[::-1]

    return ''.join(answer)



# 테스트 케이스
print(solution([6,10,2]),"6210")
print(solution([3, 30, 34, 5, 9,8]))
print(solution([0, 5, 10, 15, 20]),"52015100")
print(solution([1000, 0, 5, 99, 100]),"99510010000")
print(solution([0,0,0,0,0]),"0")
print(solution([1000,999,10,1,101]))
print(solution([2357, 235785]), 2357852357)
print(solution([90,908,89,898,10,101,1,8,9]))
