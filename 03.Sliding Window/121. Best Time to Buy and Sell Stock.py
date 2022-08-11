### Solution1 (NeetCode faster) ###
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        res = 0

        l = 0
        for r in range(1, len(prices)):
            if prices[r] < prices[l]:
                l = r
            res = max(res, prices[r] - prices[l])
        return res



### Solution2 (My method) ###
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy, sell = 0,1
        L = len(prices)
        res = 0
        
        # while buy<L and sell<L and buy<sell:
        while sell<L:
            profit = prices[sell]-prices[buy]
            res = max(res, profit)
            if prices[sell] < prices[buy]:
                buy=sell
            sell+=1
        return res