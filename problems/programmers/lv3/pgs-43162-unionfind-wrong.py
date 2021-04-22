"""
제목 : 네트워크

아이디어 : 최소 스패닝 트리
- 임의의 노드는, 0개 또는 1개의 네트워크에 연결될 수 있다.
    - 2개이상의 네트워크에 동시에 연결될 수 없다
    - (왜냐? 2개의 네트워크에 동시에 연결된다고 치면, 두 개의 네트워크가 한개로 합쳐지니까)
- 따라서, 이미 연결된 노드들은 검사할 필요가 없다.
    - 연결되지 않은 노드만 검사하면 됨
- 어떤 노드 A가 네트워크 X에 포함된 노드 B와 연결되면, 노드 A도 자동으로 네트워크 X에 포함된다
구현(또는 수도코드) :
- 유니언 파인드를 바닥부터 구현하자

- for node in n :
    - parent[node] = node

- for node in n :
    - for i,connected in computers[node] :
        - if node == i : continue
        - if connected :
            - union(i)

- def union(n) :
    - if find(n) :
        - union(n.parent)
    - else :
        - union(n)

예외처리 :
"""

def solution(n, computers):
    parent = [x for x in range(n)]

    def find(x):
        if parent[x] == x:
            return x

        parent[x] = find(parent[x])
        return parent[x]

    def union(x, y):
        x = find(x)
        y = find(y)
        if x < y : parent[y] = x
        else : parent[x] = y

    for node in range(n) :
        for i,connected in enumerate(computers[node]):
            if node == i : continue
            if connected == 1 :
                union(node,i)

    return len(set(parent))

n	= 3
computers	= [[1, 1, 0], [1, 1, 0], [0, 0, 1]]
computers = [[1, 1, 0], [1, 1, 1], [0, 1, 1]]

n = 1
computers = [[1]]

n = 3
computers = [[1, 1, 1], [1, 1, 1], [1, 1, 1]]

n = 4
computers = [[1,1,0,0],[1,1,0,1],[0,0,1,1],[0,1,1,1]]

n = 6
computers = [[1, 0, 1, 1, 0, 0], [0, 1, 0, 0, 1, 1], [1, 0, 1, 1, 1, 1], [1, 0, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1]]

print(solution(n,computers))
