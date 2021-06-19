"""
제목 : 야근 지수

아이디어 : 절대 부등식을 사용하면 된다
- 


구현 : 절대부등식을 어떻게 구현하나?
- 분산최소화?
- 작업이 완료된 후의 작업량 총합을 x라 하자
    - x가 3개에 평등하게 나뉘어져 있는 상태가 최선이다

예시 : 4 3 3
- 작업후 10-4 = 6
- 6/3 = 2*3 + 0인 것이 최선이다
    - 3개에 2를 배분한다
    - 2,2,2
- 최종 피로도는 2^2 * 3
    - 2^2 * 3 + (2+0)^2 * 0

예시 : 2,1,2
- 작업후 4
- 4/3 = 1*3 + 1인 것이 최선이다
    - 3개에 1을 배분하고, 나머지를 다시 배분한다
    - 1,1,2
- 최종 피로도는 1^2*2 + (1+1)^2*(3-2)
    - 1^2*2 + (1^2+2*1+1^2)*1

- len(works)가 변화했을 때도 탐색을 해봐야 한다
    - len(works) - 1가 가능한 경우
    - len(works) - 2
    - len(works) - 3이 가능한 경우
    ...

"""
def solution(n, works):
    works = sorted(works)
    pirodo = []
    # len(works)가 그대로인 경우
    mok, namuzi = (sum(works) - n) // len(works), (sum(works) - n) % len(works)
    pirodo.append((mok**2)*(len(works)-namuzi) + ((mok+namuzi)**2) * namuzi)

    # len(works) - 1, -2, -3, ... 가 가능한 경우
    for i in range(len(works)):
        if n >= works[i]:
            n -= works[i]
            mok, namuzi = (sum(works[i:]) - n) // len(works[i:]), (sum(works[i:]) - n) % len(works[i:])
            pirodo.append((mok ** 2) * (len(works[i:]) - namuzi) + ((mok + namuzi) ** 2) * namuzi)

    return min(pirodo)

print(solution(4,[4,3,3]),12)
print(solution(99, [2, 15, 22, 55, 55]), 580)