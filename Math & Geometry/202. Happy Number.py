### Solution1 ###
class Solution:
    def isHappy(self, n: int) -> bool:
        visit = set()
        
        while n not in visit:
            visit.add(n)
            n = self.SquareSum(n)
            
            if n==1:
                return True
        return False
        
    def SquareSum(self, n: int) -> int:
        res = 0
        while n:
            res += (n%10) ** 2
            n //=10
        return res


### Solution2 ###
class Solution:
    def isHappy(self, n: int) -> bool:
        slow, fast = n, self.SquareSum(n)
        while slow != fast:
            fast = self.SquareSum(fast)
            fast = self.SquareSum(fast)
            slow = self.SquareSum(slow)
        
        return True if fast==1 else False
    
        
    def SquareSum(self, n: int) -> int:
        res = 0
        while n:
            res += (n%10) ** 2
            n //=10
        return res
