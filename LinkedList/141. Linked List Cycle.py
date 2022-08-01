# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

##### Solution1 ######
class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        slow, fast = head, head
        
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow==fast:
                return True
        return False

##### Solution2 ######
class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        exist = []
        exist.append(head)
        while head and head.next:
            head = head.next
            if head in exist:
                return True
            else:
                exist.append(head)
        return False