"""
제목 : 여행경로

아이디어 : 그냥 DFS

구현 : 인접 dict로 구현
- 인접 리스트로 하려다가, 문자열이라서 dict
- 갔던곳을 또 가지 말라는 조건이 없으므로 주의

예외케이스 주의
- 둘 다 가능한 경로일 떄 알파벳순으로 가랬지, 불가능한데 일단 알파벳순으로 하라고는 안 했다
- 따라서, 결국 DFS로 끝까지 가본 후 가능여부를 판단해야 한다
"""

def dfs()
    # 더이상 갈 곳이 없으면(진짜 연결된게 없는 경우) 반환

    # 반환된걸 검사해서, 끝까지 갔나 판단

def solution(tickets):
    adj_dict = {}

    for ticket in tickets:
        start,end = ticket
        if start not in adj_dict:
            adj_dict[start] = []
        adj_dict[start].append(end)
    adj_dict = {k:sorted(v) for k,v in adj_dict.items()}

    answer = []
    start ="ICN"
    while start in adj_dict and adj_dict[start]:
        answer.append(start)
        start = adj_dict[start].pop(0)
    answer.append(start)
    return answer

print(solution([["ICN", "JFK"], ["HND", "IAD"], ["JFK", "HND"]]))
print(solution([["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL","SFO"]]))
