"""
제목 : 쿼드압축 후 개수 세기

아이디어 : 재귀로 풀면 된다
- 재귀 사용
    - 전체 방식과 부분문제의 방식이 동일하므로 사용 가능

구현 : 재귀 설계
- 글로벌 변수에 저장하는 방법
    - 글로벌 변수로 0과 1의 개수를 둔다
    - 탈출조건 : 영역 내의 모든 수가 동일할 떄
    - 하위 재귀 : 영역을 4개로 나눠 각 영역에 대해 재귀
- 내 영역의 0과 1 개수를 반환하는 방법
    -

- 모든 값이 1인 것을 확인할 떄 어떤 게 제일 빠를까ㅣ?
    - sum
    - count
- 좌표를 4개로 어떻게 나눌까?
    -
"""
def sum_list(x,y):
    return [x[0]+y[0],x[1]+y[1]]

def solution(arr):
    if arr.count([1]*len(arr)) == len(arr):
        return [0,1]
    if arr.count([0]*len(arr)) == len(arr):
        return [1,0]

    answer = [0,0]
    for i in range(0,len(arr),len(arr)//2):
        for j in range(0,len(arr),len(arr)//2):
            answer = sum_list(
                answer,
                solution([arr[k][i:i+len(arr)//2] for k in range(j, j+len(arr)//2)])
            )
    return answer


# 테스트 케이스
arr = [[1,1,0,0],[1,0,0,0],[1,0,0,1],[1,1,1,1]]
print(solution(arr))



