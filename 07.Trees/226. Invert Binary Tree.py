# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

### Solution1 (NeetCode) ###
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root==None:
            return None
        
        tmp = root.left
        root.left = root.right
        root.right = tmp
        
        self.invertTree(root.left)
        self.invertTree(root.right)
        
        return root


 ### Solution2 ### (自定義swap function)
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root==None:
            return None
        
        self.swap(root, root.left, root.right)
        
        self.invertTree(root.left)
        self.invertTree(root.right)
        
        return root
    
    def swap(self, root, left, right):
        tmp = root.left
        root.left = root.right
        root.right = tmp