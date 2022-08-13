# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        # if not root:
        #     return True
        
        def dfs(root):
            if not root:
                return [True, 0]
            
            Left, Right = dfs(root.left), dfs(root.right)
            balance = Left[0] and Right[0] and abs(Left[1] - Right[1]) <= 1 
            # balance = abs(Left[1] - Right[1]) <= 1 
            return [balance, 1 + max(Left[1], Right[1])]
        
        return dfs(root)[0]