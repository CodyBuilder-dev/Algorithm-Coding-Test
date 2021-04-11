"""
제목 : 후보키

아이디어 : 문제의 이해
- 후보키의 속성 이해
    - 유일성 : 모든 튜플에 대해 유일한 값을 가져야 한다
    - 최소성 : 속성이 여러개인 경우, 그중에 하나라도 뺄 수 없어야 한다. 뺄 수 있으면 후보키가 아니다
- 완전탐색 해야될 것 같은데?
- 유일성의 검증 방법
    - counter를 쓰면 된다
- 최소성의 검증 방법
    - 트라이를 서볼까?
    - Set를 쓰면 된다
수도코드
- 읽어서 리스트를 저장한다
- 가능한 모든 컬럼의 경우의 수를 뽑아 set에 저장한다
    - (0),(1),...(0,1),...(0,1,2),...(0,1,2,3,...,N-1)
    - 모든 컬럼 선택에 대해 유일성 검사
    - 해당 컬럼이 유일성을 만족할 경우 최소성 검사
        - 기존 유일성 검증된 키들에 대해 합집합을 이용한 부분집합 검사
"""
from collections import Counter
from itertools import combinations

def solution(relation):
    column_num = len(relation[0])
    keys = []
    for i in range(1,column_num+1):
        keys.extend(map(set,combinations(range(column_num),i)))


    sub_keys = []
    for key in keys:
        dataset = []
        # print(key)
        for row in relation:
            t = tuple(row[col] for col in key)

            dataset.append(t)

        # unique 검사
        c = Counter(dataset)
        if c.most_common(1)[0][1] == 1: # 개수가 1개인 경우, 중복 없음
            if not len(list(filter(lambda x:x.issubset(key), sub_keys))):
                sub_keys.append(key)

    return len(sub_keys)

# 테스트 케이스
print(solution([["100","ryan","music","2"],["200","apeach","math","2"],["300","tube","computer","3"],["400","con","computer","4"],["500","muzi","music","3"],["600","apeach","music","2"]]))
print(solution([["1"]]))
print(solution([["1","a"],["2","b"]]))
print(solution([["1","a"],["2","a"]]))
print(solution([["a","aa"],["aa","a"],["a","a"]]))
print(solution([["a","b","c"],["1","b","c"],["a","b","4"],["a","5","c"]]))
print(solution([["a",1,4],[2,1,5],["a",2,4]]))
print(solution([["ab", "c"], ["a", "bc"], ["x", "yz"], ["x", "c"]]))