"""
아이디어 : for 2개 완전탐색
- 5 * 10^4 * 10^5이므로 불가능

아이디어 : 해시 설계
- 해시 설계를 처음부터 잘 하면 아주 쉽게 풀린다
    - 쿼리의 조건이 항상 동일한 순서로 나오고, 조건도 별로 많지 않다(4*3*3*3)
    - key = 경우의 수, value = [점수]로 해도 된다
- 여기에 점수를 넣을 떄 정렬을 해서 넣어서 이진 탐색까지 해야 한다
    - 이진탐색 안하면 효율성 통과 실패
"""
import re
from bisect import *

# 아래는 잘못된 함수다! 어디가 잘못되었을까?
def lower_bound(lst, value):
    left, right = 0,len(lst)-1

    while left < right :
        mid = (left+right) // 2
        if (lst[mid] < value): left = mid +1
        else : right = mid
    return right

def solution(info, query):
    # O(info)
    people_category = {}

    for person in info :
        person_info = person.split()
        key,value = ''.join(person_info[:-1]),person_info[-1]
        if not people_category.get(key) :
            people_category[key] = []

        people_category[key].append(int(value))

    for k in people_category :
        people_category[k] = sorted(people_category[k])


    answer = []

    for q in query :
        # - 를 정규표현식을 이용해 \w로 바꿈
        q = q.replace('and', '').replace('-','\w*').split()

        count = 0

        condition = ''.join(q[:-1])
        for key in people_category :
            if re.match(condition,key) :
                if len(people_category[key]) > 1 :
                    i = bisect_left(people_category[key],int(q[-1]))

                    # i = lower_bound(people_category[key],int(q[-1]))
                    count += len(people_category[key]) - i
                else :
                    count += 1 if people_category[key][0] >= int(q[-1]) else 0

        answer.append(count)
    return answer

# 테스트 케이스
info = ["java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"]
query = [
    # "java and backend and junior and pizza 100",
    #  "python and frontend and senior and chicken 200",
    # "cpp and - and senior and pizza 250",
    "- and backend and senior and - 150",
    "- and - and - and chicken 100",
    "- and - and - and - 150"]
print(solution(info,query))
# a = int('010110', 2)
# b = int('110000', 2)
# print(bin(a & b).zfill(10))

