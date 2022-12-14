# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        n = 0
        stk = []
        cur = root
        
        while cur or stk:
            while cur:
                stk.append(cur)
                cur = cur.left
                
            cur = stk.pop()
            n+=1
            if n==k:
                return cur.val
            cur = cur.right