"""
제목 : 카펫

아이디어 : 정형화된 모양이므로, 일반화 공식을 찾을수 있을 것 같다
- 가로길이가 n, 세로길이가 m이라고 할 경우
    - 갈색 카펫은 2*n+2*m -4 = 2(n+m-2)
    - 노란 카펫은 (n-2)*(m-2)
    - n >= m (문제 제약조건에 의함)
- 즉, 연립방정식 해결 문제로 바뀌고, 이는 완전탐색을 통해 해결할 수 있다
"""

def solution(brown, yellow):
    MAX_N = 5000
    for n in range(1,MAX_N):
        for m in range(1,n+1):
            if 2*(n+m-2) == brown and (n-2)*(m-2) == yellow:
                return [n,m]

#테스트 케이스
print(solution(10,2))
print(solution(8,1))
print(solution(24,24))