class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        combn = []
        totSum = 0
        
        def dfs(i, combn, totSum):
            if totSum == target:
                result.append(combn.copy())
                return
            if i >= len(candidates) or totSum > target:
                return
            
            combn.append(candidates[i])
            # dfs(i+1, combn, totSum + candidates[i])
            dfs(i, combn, totSum + candidates[i])
            
            combn.pop()
            dfs(i+1, combn, totSum)
        
        dfs(0, combn, totSum)
        # dfs(0, combn, 0)
        return result