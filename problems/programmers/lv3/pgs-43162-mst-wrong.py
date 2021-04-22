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
- for node in nodes :
    - for i,connected in enumerate( computers[node] ):
        if connected == 1 :
            if network[i] not null : network[i].append(node)
            else : network[node].append(i)
    - if len(network[node]) == 1: del network[node]
- return len(network)
"""
def solution(n, computers):
    network = dict()
    for node in range(n):
        network[node] = []
        for i, connected in enumerate(computers[node]):
            if connected == 1 :
                if network.get(i) :
                    network[i].append(node)
                    if network.get(node) : network.pop(node)
                    break
                else : network[node].append(i)
        # if len(network[node]) == 1 : network.pop(node)


    return len(network)

n = 3
computers = [[1, 1, 0], [1, 1, 0], [0, 0, 1]]

print(solution(n,computers))