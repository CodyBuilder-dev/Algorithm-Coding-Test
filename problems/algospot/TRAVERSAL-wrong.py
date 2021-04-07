"""
제목 : 트리 순회 순서 변경

아이디어 : 전위순회, 중위순회로부터 후위순회가 도출되는 과정
(1) 전위순회의 특징 : 서브트리의 루트가 가장 먼저 읽힌다
(2) 알아낸 루트 정보를 이용해, 서브트리의 크기를 알아낸다


구현 : 클래스를 이용한다
- preorder에서 루트의 값을 알아낸다
- inorder의 루트의 index를 알아낸다
    - 그 왼쪽에 있는게 왼쪽 서브트리 개수, 오른쪽이 오른쪽 서브트리의 개수다
    - 위의 알아낸 정보들을 클래스에 집어넣는다
- 그 다음 서브트리의 루트에 대해 반복한다


결과 : 너무 쓸데없이 어렵게 구현했다
(1) Tree 클래스를 직접 구현할 필요가 없다
"""

class TreeNode:
    def __init__(self,value):
        self.value = value
        self.leftChild = None
        self.rightChild = None

    def setLeftChild(self, leftChild):
        self.leftChild = leftChild

    def setRightChild(self, rightChild):
        self.rightChild = rightChild

def postorder(root: TreeNode,result: list):

    if root.leftChild: result.extend(postorder(root.leftChild, result))
    if root.rightChild: result.extend(postorder(root.rightChild, result))

    return result.extend([root.value])


def solution():
    tc = int(input())

    for i in range(tc):
        n = int(input())
        preorder = list(map(int, input().split()))
        inorder = list(map(int, input().split()))

        root_idx = inorder.index(preorder[0])
        idx = root_idx
        t = TreeNode(preorder[0])
        root = t

        for r in preorder[1:]:
            temp_t = TreeNode(r)
            if root
            if idx < inorder.index(r):
                t.setRightChild(temp_t)
            elif idx > inorder.index(r):
                t.setLeftChild(temp_t)
            t = temp_t
            idx = inorder.index(r)

        result = postorder(root,[])

    return result

solution()