"""
제목 : 단어 변환

아이디어 : 최단거리 문제
- 변환 가능한 단어끼리는 '연결'되어 있다고 친다
- 그렇다면 결국 단어에서 단어로 이동하는 최단거리 계산 문제

구현 및 수도코드 :
(1) 그래프를 dictionary 생성한 이후
- words = words + [begin,target]
- for i in range(len(words)):
    for j in range(i,len(words)):
        if count_different_char(words[i],words[j]) == 1:
            network[words[i]].append(words[j]
            network[words[j]].append(words[i]


(2) 해당 그래프를 BFS로 최단거리 탐색

- def bfs(begin,target):
    q.push(network[begin])
    visited.add(network[begin])
    cnt = 1
    (어차피 begin과 target은 같지 않으므로, 1부터 시작해도 된다)
    ( 0인 경우는 아예 연결되지 않은 것)
    while !q.empty :
        nexters = q.pop()
        if nexters == target :
            return cnt

        for nexter in nexters :
            if !visited[nexter] :
                q.push(network[nexter])
    return 0

"""

from collections import deque



def count_different_char(a:str,b:str) -> int:
    """
    :param a: string having same length with b
    :param b: string having same length with a
    :return: number of different characters
    """
    if len(a) != len(b):
        raise Exception("두 단어의 길이가 같지 않습니다")

    cnt = 0
    for i in range(len(a)):
        if a[i] != b[i] : cnt +=1

    return cnt

def make_network(words:list)-> dict:
    empty_list =[]
    # network = dict.fromkeys(words,empty_list.copy())
    network = {key:[] for key in words}
    for i in range(len(words)):
        for j in range(0,i):
            if count_different_char(words[i], words[j]) == 1:
                network[words[i]].append(words[j])
                network[words[j]].append(words[i])

    return network

def bfs(begin:str, target:str, network:dict)->int:
    q = deque()
    visited = dict.fromkeys(network,0)

    q.append(network[begin])
    visited[begin] = 1
    cnt = 0

    while len(q) > 0 :
        nexters = q.pop()
        cnt += 1
        for nexter in nexters:
            if not visited[nexter]:
                q.append(network[nexter])
                visited[nexter] = 1
            if nexter == target:
                return cnt
    return 0


def solution(begin, target, words):
    network = make_network(words+[begin])
    answer = bfs(begin,target,network)
    return answer

begin = "hit"
target = "cog"
words = ["hot", "dot", "dog", "lot", "log", "cog"]
words = ["hot", "dot", "dog", "lot", "log"]
# print(make_network(words))
print(solution(begin,target,words))
