"""
하사드 수를 판별하는 함수를 짜보자
"""

def calc_pos_sum(x) :
    return sum(list(map(int,str(x))))

def solution(x) :
    return True if x%calc_pos_sum(x)==0 else False

if __name__ == "__main__" :
    x = 12412
    print(solution(x))