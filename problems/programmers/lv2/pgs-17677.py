"""
제목 : 뉴스 클러스터링

아이디어 :
1. 부분문자열 만들기
- 만든 후 정규표현식 이용해 특수문자 제거

2. 부분문자열 저장 자료구조 생각
- 중복 가능해야 함
-
"""
import re


def make_substr(str, i):
    result = str[i:i+2]
    if re.findall('[^a-z]', result):
        return
    else:
        return result


def solution(str1, str2):
    str1 = str1.lower()
    str2 = str2.lower()

    str1_list = []
    str2_list = []

    for i in range(len(str1)-1):
        substr = make_substr(str1, i)
        if substr:
            str1_list.append(substr)

    for i in range(len(str2)-1):
        substr = make_substr(str2, i)
        if substr:
            str2_list.append(substr)

    str_inter = set(str1_list).intersection(set(str2_list))
    str_union = str1_list + str2_list

    return int(65536*len(str_inter)/len(str_union))



print(solution("FRANCE","french"),16384)
# print(make_substr("ab+", 0))
