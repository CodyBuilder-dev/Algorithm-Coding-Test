"""
제목 : [1차] 캐시

아이디어 : 스케쥴링 알고리즘의 구현
- LRU에 대한 이해
    - 마지막으로 사용된 시간이 가장 긴 놈 찾기
    - 사용된 시간에 대한 값 자체를 저장하거나, 적어도 사용순서에 따라 순서가 유지되어야 한다
- stack과 queue의 속성을 동시에 가지는 deque를 쓰면되지 않을까?
    - 평소에는 오른쪽으로만 삽입 -> 가장 오래전에 삽입된 것이 왼쪽으로 몰림
    - 그런데 문제점은 호출시 인덱스로 접근 및 push/pop이 가능한지가 문제다
    - 다행히 python 3.5이상에서는 deque에 인덱싱을 지원하지만, 그 전에는 어쩔 수 없이 list로 짜야 한다
    - 그리고 이름을 통해 O(1)로 접근하려면 dict를 써야한다
구현 : 그냥 리스트에 들어온 걸 순서대로 처리한다
- 캐시
"""
def solution(cacheSize, cities):
    hash = dict()

    if not cacheSize:
        return len(cities)*5

    run_time = 0
    for city in cities:
        city = city.lower()

        if city not in hash: # 없을 경우, 캐시 미스
            if len(hash) == cacheSize:
                hash.pop(max(hash,key=hash.get))
            run_time += 5

        else: # 있을 경우 캐시 히트
            run_time += 1

        for k in hash:
            hash[k] +=1
        hash[city] = 0
    return run_time

# 테스트 케이스
# print(solution(3,["Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"]),50)
print(solution(2,["Jeju", "Pangyo", "NewYork", "newyork"]),16)
print(solution(0,["Jeju", "Pangyo", "Seoul", "NewYork", "LA"]),25)
print(solution(0,[]),0)
print(solution(1,["Jeju", "Pangyo", "NewYork", "newyork"]),16)
print(solution(5,["Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"]))
