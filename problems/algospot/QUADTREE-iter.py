# 이터레이터를 이용해 구현
def check_x(iter_qt):
    current_char = next(iter_qt)
    if current_char == 'w' or current_char == 'b':
        return [current_char]

    upper_left = check_x(iter_qt)
    upper_right = check_x(iter_qt)
    lower_left = check_x(iter_qt)
    lower_right = check_x(iter_qt)

    return ['x'] + lower_left + lower_right + upper_left + upper_right

# 제출용 함수
def solution():
    c = int(input())
    for i in range(c):
        quad_tree = list(input())
        qt_iter = iter(quad_tree)
        print(''.join(check_x(qt_iter)))

# 테스트용 함수
def solution_t(*args):
    c = args[0]
    for i in range(c):
        quad_tree = args[1]
        qt_iter = iter(quad_tree)
        return ''.join(check_x(qt_iter))

solution()

# 수동 테스트케이스
# print(solution(1,'xbbbw'))
print(solution(1,'xxwwwbxwxwbbbwwxxxwwbbbwwwwbb'))
print('xxwbxwwxbbwwbwbxwbwwxwwwxbbwb')

# 자동화 테스트 케이스
# assert solution(1,'w') == 'w'
# assert solution(1,'b') == 'b'
# assert solution(1,'xbbbw') == 'xbwbb'
# assert solution(1,'xwwwb') == 'xwbww'
# assert solution(1,'xbwxwbbwb') == 'xxbwwbbbw'
# assert solution(1,'xxbwwbbbw') == 'xbwxwbbwb'
# assert solution(1,'xbwwb') == 'xwbbw'
# assert solution(1,'xxwwwbxwxwbbbwwxxxwwbbbwwwwbb') == 'xxwbxwwxbbwwbwbxwbwwxwwwxbbwb'
# assert solution(1,'xxwbxwwxbbwwbwbxwbwwxwwwxbbwb') == 'xxwwwbxwxwbbbwwxxxwwbbbwwwwbb'
