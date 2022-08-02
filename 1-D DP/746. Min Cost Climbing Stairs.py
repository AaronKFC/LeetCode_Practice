### Solution1 ###
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        cost.append(0)
        
        for i in range(len(cost)-3, -1, -1):
            cost[i] += min(cost[i+1], cost[i+2])
        
        return min(cost[0] , cost[1])

### Solution2 ###
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        down1, down2 = 0, 0 
        
        for i in range(2, len(cost)+1):
            tmp = down1
            down1 = min(down1 + cost[i-1], down2 + cost[i-2])
            down2 = tmp
        return down1
        
