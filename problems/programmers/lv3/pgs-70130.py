"""
제목 : 스타 수열

아이디어 : 자릿수가 50만개다
- 2^50만 또는 Combination으로는 접근이 불가능하다

아이디어 : 조건을 잘 해석한다
- 교집합의 개수는 1 이상이어야 한다
    - 즉, x[0] == x[2] or x[1] == x[2] or x[0] == x[3] or x[1] == x[3]

- 즉, 가장 많이 출현하는 놈을 기준으로 삼는다
    - 가장 많이 출현하는놈이 여럿이면 모두 찾는다
    - 즉, 가능한 모든 원소에 대해 완전탐색을 하는 것

- 가장 많이 출현한놈의 위치를 기준으로 검사한다
    - 가장 많이 출현하는놈들의 위치를 알아낸다
    - 해당 위치를 기준으로 좌우로 붙인 애들의 set을 만드는 함수
    - 해당 set의 원소만 뽑앗을 때, 그게 스타 수열인지 알려주늖 ㅏㅁ수
    - 스타수열일 경우 해당 수열의 길이 저장
    
- 토너먼트랑 비슷하게 검사?
    - (idx+1)//2가 같으면 못 붙임
    - (idx+1)//2가 다르면 붙일 수 있음
    -> 잘 안됨


"""
from collections import Counter

def solution(a):
    if len(a) <= 1:
        return 0

    idx_list = [i for i,x in enumerate(a) if x == Counter(a).most_common(1)[0][0]]
    idx_list = list(map(lambda x:x//2,idx_list))
    c = len(Counter(idx_list).keys())
    return c*2

# 테스트 케이스
print(solution([]),0)
print(solution([1]),0)
print(solution([5,6,4,6,4,1,2,3,2]),4)
print(solution([2,3,3,4,1,3]),6)
print(solution([3,3,3,3,3,3]),0)
print(solution([3,2,3,2,3,2]),6)
print(solution([4,4,1,4,2,4]),4)
print(solution([3,1,2,3,4]),4)
print(solution([2,2,0,0,3,3]),4)

