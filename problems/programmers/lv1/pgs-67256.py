"""
제목 : 키패드 누르기

아이디어 : 그냥 구현하면 된다
- 손가락별로 현재 위치 가로 세로만 저장한다
- 1,4,7 과 3,6,9면 누른다
- 2,5,8,0이면 키로부터 거리를 구한다
    - 거리가 짧은쪽 손으로 누른다
    - 거리가 같으면 선호하는 손으로 누른다
- 손의 좌표를 초기화하고 거리를 추가한다
"""

def solution(numbers, hand):
    coord = {
        1: (0, 0),
        2: (0, 1),
        3: (0, 2),
        4: (1, 0),
        5: (1, 1),
        6: (1, 2),
        7: (2, 0),
        8: (2, 1),
        9: (2, 2),
        0: (3, 1),
    }

    left = (3,0)
    right = (3,2)

    answer = ''
    for number in numbers :
        if number in [1,4,7]:
            answer += "L"
            left = coord[number]
        if number in [3,6,9]:
            answer += "R"
            right = coord[number]
        if number in [2,5,8,0]:
            dist_from_left = abs(left[0]-coord[number][0]) \
                            +abs(left[1]-coord[number][1])
            dist_from_right = abs(right[0] - coord[number][0]) \
                            +abs(right[1] - coord[number][1])
            if (dist_from_left < dist_from_right and hand == "right") \
                or (dist_from_left <= dist_from_right and hand == "left") :
                answer+="L"
                left = coord[number]
            else :
                answer += "R"
                right = coord[number]

    return answer

print(solution([1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5],"right"),"LRLLLRLLRRL")
print(solution([7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2],"left"),"LRLLRRLLLRR")