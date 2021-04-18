"""
제목 : 체육복
"""
def solution(n, lost, reserve):
    _reserve = [r for r in reserve if r not in lost]
    _lost = [l for l in lost if l not in reserve]
    for r in _reserve:
        f = r - 1
        b = r + 1
        if f in _lost:
            _lost.remove(f)
        elif b in _lost:
            _lost.remove(b)
    return n - len(_lost)

print(solution(5,[2,4],[1,3,5]),5)
print(solution(5,[2,4],[3]),4)
print(solution(3,[3],[1]),2)
print(solution(7,[1,2,3],[5,6,7]),4)
print(solution(7,[1,2,3],[1,2,3]))
print(solution(5,[2,4],[3,1]),5)