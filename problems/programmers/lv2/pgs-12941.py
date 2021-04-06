"""
제목 : 최솟값 만들기

아이디어 : 2번 정렬해서 큰것과 작은것을 곱하면 됨

아이디어의 증명 :


"""

def mult_list(A,B):
    return [x*y for x,y in zip(A,B)]

def solution(A,B):
    return sum(mult_list(sorted(A),sorted(B,reverse=True)))

print(solution([1, 4, 2],[5, 4, 4]))

