# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    """
    아이디어 : 리스트로 변환해서 풀이
    1. 순회하여 리스트로 만든 후 이를 정렬한다
    2. 정렬된 리스트로부터 링크드 리스트를 만든다
    """
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        numlist = []
        while l1 :
            numlist.append(l1.val)
            l1 = l1.next
        while l2 :
            numlist.append(l2.val)
            l2 = l2.next

        head = None
        for num in sorted(numlist):
            if not head :
                head = ListNode()
                head.val = num
                tail = head
            else :
                temptail = ListNode()
                temptail.val = num
                tail.next = temptail
                tail = tail.next

        return head

class Solution2:
    """
    아이디어 : 병합정렬의 아이디어를 채용
    1. 두 개의 링크드리스트를 동시에 검사하며 작은놈을 별도로 보관
    """

    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = ListNode()
        tail = head
        while l1 and l2 :
            if l1.val >= l2.val :
                tail.next = l2
                tail = tail.next
            else :
                tail.next = l1
                tail = tail.next
        return head

