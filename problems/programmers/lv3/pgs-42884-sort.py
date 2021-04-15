"""
제목 : 단속카메라

아이디어 :
- 나가는 시간 순으로 정렬한다
"""
def solution(routes):
    # 나가는 시간 순 정렬
    routes = sorted(routes,key=lambda x:x[1])
    print(routes)
    camera = 1
    temp = routes[0]
    # 공통부분 찾기
    for i,route in enumerate(routes[1:],start=1):
        if temp[1] >= routes[i][0]:
            # 오름차순이므로, 굳이 나가는 시간에 min를 적용할 필요 없음
            # temp = [max(temp[0],routes[i][0]),min(routes[i][1],routes[i-1][1])]
            temp = [min(temp[0],routes[i][0]),temp[1]]
        else:
            camera += 1
            temp = routes[i]
    return camera



# 테스트 케이스
print(solution([[-20,15], [-14,-5], [-18,-13], [-5,-3]]),2)
print(solution([[0,12],[1,12],[2,12],[3,12],[5,6],[6,12],[10,12]]),2)
print(solution([[0, 0], [0, 0], [2, 2]]), 2)
print(solution([[2, 2],[0, 1],[-10,9]]),2)
print(solution([[0, 4], [1, 2], [2, 3], [1, 3], [3, 4], [0, 1]]),2)
print(solution([[-100,100],[50,170],[150,200],[-50,-10],[10,20],[30,40]]))
print(solution([[-191, -107], [-184, -151], [-150, -102], [-171, -124], [-120, -114]]),8)
print(solution([[0, 12], [1, 12], [2, 12], [3, 12], [5, 6], [6, 12], [10, 12]]),2)
print(solution([[0, 0]]),1)
print(solution([[0, 1], [1, 2], [2, 3], [3, 4], [4, 5], [5, 6], [6, 7], [7, 8], [8, 9], [9, 10], [10, 11], [11, 12], [12, 13], [13, 14], [14, 15]]),4)
print(solution([[-7, 0], [-6, -4], [-5, -3], [-3, -1], [-1, 4], [1, 2], [3, 4]]),2)
print(solution([[0, 12], [1, 12], [2, 12], [3, 12], [5, 6], [6, 12], [10, 12]]),4)
print(solution([[0, 1], [1, 2]] ))