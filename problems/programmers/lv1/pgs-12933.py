"""
제목 : 정수 내림차순으로 배치하기

아이디어 : 그냥 구현하면 됨

구현 : 극한의 숏코드를 추구해보자
"""
def solution(n):
    return int(''.join(sorted(str(n),reverse=True)))