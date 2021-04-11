"""
제목 : 요새

아이디어 : 계층구조이므로 트리를 이용하겠다는 아이디어를 떠올리면 된다
(1) 성곽 내에 성곽이 들어간 경우, 자식으로 친다
- 중심간 거리가 반지름와 어떤관계를 갖는지 검사한다
    - 중심간 거리가 두 반지름 합보다 크면, 전혀 관계없다
    - 중심간 거리가 큰 반지름보다 작으면 포함되는 것이다
        - 중심간 거리 + 작은 반지름  <= 큰 반지름
(2) 가장 성벽을 많이 넘는 것은, 가장 멀리 떨어진 노드까지의 거리이다
- 아마 루트의 노드 중 가장 깊은 것 2개의 합이 아닐까?
"""
class Tree:
    def __init__(self,x,y,r):
        self.children = []
        self.center = (x,y)
        self.r = r

def insert(t: Tree,root: Tree):
    for child in root.children:
        dist = ((t.x - child.x)**2 + (t.y - child.y)*2)**0.5
        if dist + min(t.r,child.r) <= max(t.r,child.r):
            pass


def solution():
    c = int(input())
    n = int(input())
    for i in range(n):
        x,y,r = map(int,input())