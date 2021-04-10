"""
제목 : 쿼드 트리 뒤집기

아이디어 : 직접 구현한다
- 쿼드트리를 복원하여 그림을 만들고 다시 압축한다
    -> 문자열을 리스트로 바꾸는 것이므로 매우 어려운 구현문제로 바뀜
    -> 그림의 사이즈가 크므로 공간복잡도와 시간복잡도가 커짐

아이디어 : 규칙을 찾는다
- 상하로 뒤집는 것은 1<->3, 2<->4를 교환하는 것이다
- x 뒤의 4개의 덩어리를 검사해 교환하면 된다

구햔 : 재귀 이용
- 첫번재 자리를 검사한다
    - 만약 w,b이면 그냥 그대로 둔다
    - 만약 x이면, x뒤에서부터 4자리를 검사한다
        - 4자리 중에 x가 나오면 또 재귀적으로 호출한다
        - 4자리에 x가 없으면 그냥 1<->3,2<->4
"""
def check_x(qt,i):
    if qt[i] == 'w' or qt[i] == 'b':
        return qt[i]

    temp_answer = []
    k = 1
    for j in range(4):
        # print(i + k)
        temp_answer.append(check_x(qt, i + k))
        k += len(temp_answer[j])

    answer = []
    answer.extend('x')
    answer.extend(temp_answer[2])
    answer.extend(temp_answer[3])
    answer.extend(temp_answer[0])
    answer.extend(temp_answer[1])
    return answer

# 제출용 함수
def solution():
    c = int(input())
    for i in range(c):
        quad_tree = list(input())
        print(''.join(check_x(quad_tree,0)))

# 테스트용 함수
def solution_test(*args):
    c = args[0]
    for i in range(c):
        quad_tree = args[1]
        return ''.join(check_x(quad_tree,0))

# 제출용
solution()

# 자동화 테스트 케이스
assert solution(1,'xxwbbwxbwwbxwbbwxbwwb')

# assert solution(1,'w') == 'w'
# assert solution(1,'b') == 'b'
# assert solution(1,'xbbbw') == 'xbwbb'
# assert solution(1,'xwwwb') == 'xwbww'
# assert solution(1,'xbwxwbbwb') == 'xxbwwbbbw'
# assert solution(1,'xxbwwbbbw') == 'xbwxwbbwb'
# assert solution(1,'xbwwb') == 'xwbbw'
# assert solution(1,'xxwwwbxwxwbbbwwxxxwwbbbwwwwbb') == 'xxwbxwwxbbwwbwbxwbwwxwwwxbbwb'
# assert solution(1,'xxwbxwwxbbwwbwbxwbwwxwwwxbbwb') == 'xxwwwbxwxwbbbwwxxxwwbbbwwwwbb'
