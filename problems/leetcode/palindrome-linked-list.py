class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    """
    아이디어
    1. 링크드 리스트는 slicing등이 불가능하다
    -> 직접 탐색할수밖에 없다
    -> 단방향 링크드 리스트이므로 양쪽에서 동시에 찾는 것이 불가능하다
    -> 링크드 리스트를 그냥 리스트로 바꿔서 풀자
    2. 시간복잡도 O(N)이지만, 추가적인 별도의 리스트 저장공간이 O(N)필요하다
    """
    def isPalindrome(self, head: ListNode) -> bool:
        val_list = []
        while head :
            val_list.append(head.val)
            head = head.next

        return True if val_list == val_list[::-1] else False

"""
링크드 리스트는 로컬에서 테스트하기가 까다로운데, 해결책이 있을까?
"""
s = Solution()
print(s.isPalindrome())

class Solution2:
    """
    아이디어 :런너(Runner) 기법을 이용
    -> 펠린드롬은 중간부터 거꾸로 읽어서 확인하면 된다
    -> 중간이 어딘지 알려면, 빠른 런너와 느린 런너를 출발시켜 알 수 있다

    1. 빠른런너 느린런너 동시 출발
    2. 빠른런너가 더 나아가지 못하면 그때가 중간
    3. 느린 런너는 그때부터 천천히 한칸씩 비교하며 나아감
    """
    def isPalindrome(self, head: ListNode) -> bool:
        # 길이가 0 또는 1인 펠린드롬에 대해서 True
        if not head or not head.next : return True

        fast, slow = head,head
        newHead = ListNode()

        # 중간까지 가는 길
        while True :
            tempHead = newHead
            newHead = ListNode()
            newHead.val = slow.val
            newHead.next = tempHead

            fast = fast.next.next
            slow = slow.next

            if not fast.next or not fast :
                break
        # 중간도달 이후 비교하며 전진
        if fast :
            slow = slow.next

        while slow :
            if newHead.val != slow.val :
                return False
            slow = slow.next
            newHead = newHead.next
        return True

