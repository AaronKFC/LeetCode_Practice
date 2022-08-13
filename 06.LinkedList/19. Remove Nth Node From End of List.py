### Solution1 (NeetCode) ###
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)  # 關鍵是怎麼快速知道要設dummy node？
        left = dummy
        right = head
        
        while n>0 and right:
            right = right.next
            n-=1
        
        while right:
            left = left.next
            right = right.next
        
        left.next = left.next.next
        return dummy.next


### Solution2 ### (不用dummy的解法)
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if head.next==None:
            return None
                
        left = head
        right = head
        
        while n>0 and right:
            right = right.next
            n-=1
        
        if right==None:
            return head.next
        
        while right.next:
            left = left.next
            right = right.next
        
        left.next = left.next.next
        return head




