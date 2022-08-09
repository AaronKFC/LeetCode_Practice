### Solution1 ###
class Solution:
    def countBits(self, n: int) -> List[int]:
        dp = [0] * (n+1)
        
        for i in range(1,n+1,1):
            # dp[i] = dp[i>>1] + i&1 #這樣寫會有問題
            dvd2 = dp[i>>1]
            mod2 = i&1
            dp[i] = dvd2 + mod2
        return dp
        

### Solution2 ###
class Solution:
    def countBits(self, n: int) -> List[int]:
        dp = [0] * (n+1)
        offset = 1
        
        # for i in range(n+1):
        for i in range(1, n+1):
            if offset*2 == i:
                offset = i
            dp[i] = 1 + dp[i - offset]
        return dp
