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
    아이디어 : 리스트로 변환해서 풀이
    1. 순회하여 리스트로 만든 후 이를 정렬하면 편하게 풀 수 있다
    """

    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode: