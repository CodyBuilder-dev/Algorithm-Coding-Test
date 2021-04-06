"""
제목 : 메뉴 리뉴얼

아이디어 : 이거 해시임 ㅋㅋ
- 해시의 key를 단품요리 알파벳들로 한다
- 각 value를 선택된 숫자로 한다
- 선택된 숫자를 기준으로 정렬한다

구현 : dict
- order를 읽는다
    - course에 있는 숫자를 기준으로 조합을 추출한다
    - key로 만들어서 넣는다
- 마지막에 dict를 정렬하고, 2개 이상인 것들만 추출한다
    - 사전순으로 정렬한다

"""
from itertools import combinations

def solution(orders, course):
    hash = {}
    for order in orders:
        for c in course:
            lst = combinations(order,c)
            for k in lst:
                k = tuple(sorted(k))
                if not hash.get(k): hash[k] = 0
                hash[k] += 1
    # 최대값 구하기
    course_max = dict.fromkeys(course,0)
    for k,v in hash.items():
        if (v > course_max[len(k)]):
            course_max[len(k)] = v

    course_max = {k:v for k,v in course_max.items() if v >=2}

    result = []
    for k, v in hash.items():
        for c in course_max:
            if len(k) == c and v == course_max[c]:
                result.append(''.join(k))

    return sorted(result)

print(solution(["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"],[2,3,4]))
