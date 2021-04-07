"""
제목 : 최댓값과 최솟값

아이디어 : 굉장히 쉬운 문제이므로, 단순히 푸는것만으로 끝내기보단
깔끔하게 숏코딩하는 방법을 연구하는 것이 좋다

구현 : 별표 연산자를 사용해 언패킹처리로 구현
"""
def solution(s):
    min, *others, max = sorted(map(int,s.split()))
    return f"{min} {max}"