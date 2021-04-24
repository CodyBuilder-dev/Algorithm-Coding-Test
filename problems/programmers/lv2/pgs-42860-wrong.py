"""
제목 : 조이스틱

아이디어 : 조이스틱이 좌우로 자유롭게 이동가능하다고 가정
(1) 수평으로 가장 가까운 NOT A 버튼으로 이동
- 왼쪽/오른쪽으로 보내본다
    - 왼쪽으로 가장 최초로 NOT A가 나올떄까지의 거리를 찾는다
    - 오른쪽도 마찬가지
- 계속 가서 한바퀴(len)이상 찾아도 NOT A 안나오면 문자열이 모두 A인 경우
    - 0 반환 후 종료
- 둘중 더 가까운 칸으로 이동한다
- 어느 칸으로 갈지 결정되면, 이동거리를 계산한다
    - 거리가 len//2 초과이면 반대로 가는게 빠르다
    - 거리가 len//2 이면 동일하다
    - 거리가 len//2 미만이면 원래대로 가는게 맞다

(2) 수직 이동거리 계산
- 최소거리 조건
    - 거리가 27//2 = 13 초과이면 반대로 가는게 빠르다
    - 거리가 13이면 위아래 동일하다
    - 거리가 13미만이면 제대로 가는게 빠르다
- 구현
    - min(x,26-x)으로 처리
"""
from math import inf

def choice_lr(name,index) :
    # right
    right_len = 0
    i,j = index,index
    while name[i] == 'A':
        if (right_len) > len(name):
            return -inf
        i = (i+1) % len(name)
        right_len += 1

    # left
    left_len = 0
    while name[j] == 'A':
        if (left_len) > len(name):
            return -inf
        j = (j - 1) % len(name)
        left_len += 1
    return -1*left_len if left_len < right_len else right_len

def solution(name):
    name = [x for x in name]

    point = 0
    total_move = 0
    while True :
        # 좌우 이동
        direction =choice_lr(name,point)
        if direction == -inf: break
        point = (point + direction) % len(name)
        total_move += abs(direction)

        #상하 이동
        dist_ud = abs(ord(name[point])-ord("A"))
        total_move += min(dist_ud,26-dist_ud)
        name[point] = "A"


    answer = total_move
    return answer

#테스트 케이스, 설명대로의 정답, 실제 테스트케이스의 정답
print(solution("DAZ"),5,5)
print(solution("ABAAAAAAAAABB"),7,7)
print(solution("JAJAAAJ"),32, 31)


