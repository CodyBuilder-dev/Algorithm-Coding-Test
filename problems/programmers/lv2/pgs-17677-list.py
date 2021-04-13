"""
제목 : 뉴스 클러스터링

아이디어 :
1. 부분문자열 만들기
- 2글자씩 잘라내기
- 만든 후 정규표현식 이용해 특수문자 제거

2. 부분문자열 저장 자료구조 생각
- 기존 set에 중복 허용처리를 할 것이냐 vs 기존 list에 합집합, 교집합 연산을 적용할것인가
-> list에 교집합과 합집합을 구현하자

"""
import re


def make_substr(str, i):
    result = str[i:i+2]
    if not re.findall('[^a-z]', result):
        return result


def intersect_list(lst1,lst2):
    lst1 = sorted(lst1)
    lst2 = sorted(lst2)

    result = []
    for a in lst1:
        if a in lst2:
            result.append(a)
            lst2.remove(a)
    return result

def union_list(lst1,lst2):
    lst1 = sorted(lst1)
    lst2 = sorted(lst2)

    for a in lst1:
        if a in lst2:
            lst2.remove(a)
    return lst1 + lst2


def solution(str1, str2):
    str1_list = [make_substr(str1.lower(),i) for i in range(len(str1)-1) if make_substr(str1.lower(),i)]
    str2_list = [make_substr(str2.lower(),i) for i in range(len(str2)-1) if make_substr(str2.lower(),i)]


    str_inter = intersect_list(str1_list,str2_list)
    str_union = union_list(str1_list,str2_list)

    if not str_union: return 65536
    else: return int(65536*len(str_inter)/len(str_union))


# 테스트 케이스
# print(solution("FRANCE","french"),16384)
# print(solution("ABDDD", "DDEFGHH"),7281);
# print(solution("AACCC", "A A A A A C C C C"),0);
print(solution("AAbbaa_AA", "BBB"),9362);
print(solution("CCDEFGHH", "ABCCC"),6553);
print(solution("FRANCE", "french"),16384);
print(solution("handshake", "shake hands"),65536);
print(solution("aa1+aa2", "AAAA12"),43690);
print(solution("E=MC2", "e=mc2"),65536);
# print(make_substr("ab+", 0))

