"""
제목 : 징검다리 건너기

아이디어 : 스택 사용(아이디어를 주신 steel fox님에게 감사드립니다)
-
"""
MAXN = int(2e8) # int해주지 않으면 float으로 생성됨
def solution(stones, k):
    stones.append(MAXN+1)
    answer = MAXN+1

    stack = []
    stack.append([-1,MAXN+1])

    p_count = -1
    for i in range(len(stones)):
        while i - stack[-1][0] <= k and stack[-1][1] <= stones[i]:
            p_count = stack[-1][1]
            stack.pop()

        if p_count != -1 and stack[-1][0] > k:
            answer = min(answer,p_count)
            p_count = -1
        stack.append([i,stones[i]])

    return answer

