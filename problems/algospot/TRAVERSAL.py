"""
제목 : 트리 순회 순서 변경

아이디어 : 전위순회, 중위순회로부터 후위순회가 도출되는 과정
(1) 전위순회의 특징 : 서브트리의 루트가 가장 먼저 읽힌다
(2) 알아낸 루트 정보를 이용해, 서브트리의 크기를 알아낸다


구현 : 그냥 리스트를 이용한다
재귀를 이용해, 다음 서브트리에
- 현재 루트를 제외한 preorder 정보
- 현재 루트를 제외한 inorder 정보
이후, 내 루트 값을 출력한다

"""
def printPostOrder(preorder: list, inorder: list):
    n = len(preorder)
    if not preorder: return
    root = preorder[0]
    left,right = inorder.index(root), n - 1 - inorder.index(root)
    printPostOrder(preorder[1:left+1],inorder[0:left])
    printPostOrder(preorder[left+1:n], inorder[left+1:n])
    print(root,end = ' ')

def solution():
    tc = int(input())

    for i in range(tc):
        n = int(input())
        preorder = list(map(int, input().split()))
        inorder = list(map(int, input().split()))

        printPostOrder(preorder,inorder)


solution()