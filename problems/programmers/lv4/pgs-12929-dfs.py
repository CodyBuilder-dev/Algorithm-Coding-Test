answer = 0

def dfs(open,close,cnt,total):
    global answer
    if open > total/2 or close > total/2: return
    if close > open: return
    if cnt==total:
        answer+=1
        return

    dfs(open+1,close,cnt+1,total)
    dfs(open,close+1,cnt+1,total)

def solution(n):
    global answer
    answer = 0
    dfs(0,0,0,n*2)
    return answer

for i in range(1,15):
    print(solution(i))