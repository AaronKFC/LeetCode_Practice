
### Solution (NeetCode) ###
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        stk = []
        res = []
        
        def backtrack(openN, closeN):
            if openN==closeN==n:
                res.append("".join(stk))
                return
            
            if openN < n:
                stk.append("(")
                backtrack(openN+1, closeN)
                stk.pop()  # 要pop的原因：因為stack是要重覆使用的global variable，非因要消除括號。
            
            if closeN < openN:
                stk.append(")")
                backtrack(openN, closeN+1)
                stk.pop()  # 要pop的原因：因為stack是要重覆使用的global variable，非因要消除括號。
        
        backtrack(0,0)
        return res