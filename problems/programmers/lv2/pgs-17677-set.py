"""
제목 : 뉴스 클러스터링

아이디어 :
1. 부분문자열 만들기
- 2글자씩 잘라내기
- 만든 후 정규표현식 이용해 특수문자 제거

2. 부분문자열 저장 자료구조 생각
- 기존 set에 중복 허용처리를 할 것이냐 vs 기존 list에 합집합, 교집합 연산을 적용할것인가
-> 아무리 봐도 기존 set를 쓰는 것이 편하다

"""
import re
from collections import Counter


def make_substr(str, i):
    result = str[i:i+2]
    if not re.findall('[^a-z]', result):
        return result


def solution(str1, str2):
    str1_list = [make_substr(str1.lower(),i) for i in range(len(str1)-1) if make_substr(str1.lower(),i)]
    str2_list = [make_substr(str2.lower(),i) for i in range(len(str2)-1) if make_substr(str2.lower(),i)]

    str1_set = []
    str2_set = []
    for k,cnt in Counter(str1_list).items():
        for c in range(cnt):
            str1_set.append((k,c))

    for k,cnt in Counter(str2_list).items():
        for c in range(cnt):
            str2_set.append((k,c))

    str_inter = set(str1_set).intersection(set(str2_set))
    str_union = set(str1_set).union(set(str2_set))

    if not str_union: return 65536
    else: return int(65536*len(str_inter)/len(str_union))


# 테스트 케이스
print(solution("FRANCE","french"),16384)
print(solution("ABDDD", "DDEFGHH"),7281);
print(solution("AACCC", "A A A A A C C C C"),0);
print(solution("AAbbaa_AA", "BBB"),9362);
print(solution("CCDEFGHH", "ABCCC"),6553);
print(solution("FRANCE", "french"),16384);
print(solution("handshake", "shake hands"),65536);
print(solution("aa1+aa2", "AAAA12"),43690);
print(solution("E=MC2", "e=mc2"),65536);
# print(make_substr("ab+", 0))

