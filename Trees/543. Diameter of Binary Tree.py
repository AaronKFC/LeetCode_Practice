# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        # result = [0]
        global result #注意這裡也要加global
        result=0
        
        def dfs(root):
            if not root:
                return -1
            
            Lheight = dfs(root.left)
            Rheight = dfs(root.right)
            global result
            # result[0] = max(result[0], (Lheight + Rheight +2))
            result = max(result, (Lheight + Rheight +2))
            
            return 1 + max(Lheight, Rheight)
        
        dfs(root)
        # return result[0]
        return result