"""
제목 : 조이스틱

아이디어 :
- A인 거는 가만히 놔둔다
- A가 아닌 다음 놈의 거리를 구한다
    - 거리가 len//2 초과이면 반대로 가는게 빠르다
    - 거리가 len//2 이면 동일하다
    - 거리가 len//2 미만이면 원래대로 가는게 맞다

- 위아래 거리를 구한다
    - 거리가 27//2 = 13 초과이면 반대로 가는게 빠르다
        - AB
    - 거리가 13이면 위아래 동일하다
    - 거리가 13미만이면 제대로 가는게 빠르다

구현 :
세로거리 구하기 함수
- A와 B 크기 비교
    - B가 크면 B-A반환
    - A가 크면 B+27-A반환

가로축 제일 가까운 NOT A버튼으로 이동
- 왼쪽 오른족에 똑같은 문자열 하나씩 붙인다다- 왼쪽으로 보내본다
    - A아닌거 나올떄까지의 거리를 찾는다
- 오른쪽으로 보내본다
    - 마찬가지
- 계속 가서 한바퀴(len)이상 가도 A아닌게 안나오면 없는거임
    - 반환 0
"""
def choice_lr(name,index) :
    # right
    right_len = 0
    i,j = index,index
    while name[i] == 'A' :
        if (right_len) > len(name) :
            return -987654321
        i = (i+1) % len(name)
        right_len +=1

    # left
    left_len = 0
    while name[j] == 'A':
        if (left_len) > len(name):
            return -987654321
        j = (j - 1) % len(name)
        left_len += 1
    return -1*left_len if left_len < right_len else right_len

def solution(name):
    name = [x for x in name]
    visited = [0]*len(name)

    point = 0
    total_move = 0
    while True :
        # 좌우 이동
        direction =choice_lr(name,point)
        if direction == -987654321 : break
        point = (point + direction) % len(name)
        total_move += abs(direction)

        #상하 이동
        dist_ud = abs(ord(name[point])-ord("A"))
        total_move += min(dist_ud,26-dist_ud)
        name[point] ="A"


    answer = total_move
    return answer

#테스트 케이스, 설명대로의 정답, 등록 해답의 정답
print(solution("DAZ"),5,5)
print(solution("ABAAAAAAAAABB"),7,7)
print(solution("JAJAAAJ"),32, 31)


