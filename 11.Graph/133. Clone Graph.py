"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        old2new = {}
        
        def dfs(node):
            if node in old2new:
                return old2new[node] # 注意是要return已存在的node
            copy = Node(node.val)
            old2new[node] = copy
            for neib in node.neighbors:
                # copy.neighbors.append(neib) #要recurrsion才對
                copy.neighbors.append(dfs(neib))
            return copy
        
        return dfs(node) if node else None