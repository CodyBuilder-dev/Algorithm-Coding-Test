"""
제목 : 팬미팅

아이디어 : 직접 구현
- 한칸씩 옆으로 움직이면서 직접 횟수를 센다
-> O(N)만 해도 2*10^5이고, 돌면서 체크하면 O(N^2)이므로 시간 초가

아이디어 : 문제 본질 이해
- 모든 멤버들이 포옹을 한다
    - M = 0, F = 1 로 한다
    - M = 0 or F = 1 했을 때 0이면 실패한다
1 1|1
1 0|1
0 1|1
0 0|0
-> 시간초과
"""
def calc(members,fans):
    members = ''.join(['1' if m == 'F' else '0' for m in members ])
    fans = ''.join(['1' if f == 'F' else '0' for f in fans])

    count = 0
    for i in range(0,len(fans)-len(members)+1):
        result = int(fans[i:i+len(members)],2) | int(members,2)
        if result == 2**len(members)-1:
            count += 1
    return count

def solution():
    c = int(input())
    for i in range(c):
        members = input()
        fans = input()

        print(calc(members,fans))


def solution_t(*args):
    c = args[0]
    for i in range(c):
        members = args[1]
        fans = args[2]

        return(calc(members,fans))

solution()

print(solution_t(1,"FFFMMM","MMMFFF"))
print(solution_t(1,"FFFFF","FFFFFFFFFF"))
print(solution_t(1,"MFMFMFFFMMMFMF","MMFFFFFMFFFMFFFFFFMFFFMFFFFMFMMFFFFFFF"))
print(solution_t(1,"FFFFM","FFFFFMMMMF"))

