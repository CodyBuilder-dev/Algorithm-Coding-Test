"""
제목 : 로또의 최고 순위와 최저 순위
"""
def solution(lottos, win_nums):
    unknown = lottos.count(0)
    matched = len(set(lottos).intersection(set(win_nums)))
    return [7 - max(1,matched + unknown), 7 - max(1,matched)]