### Solution1 ###
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        Scnt, Tcnt = {}, {}
        
        for c,d in zip(s,t):
            Scnt[c] = 1 + Scnt.get(c, 0)
            Tcnt[d] = 1 + Tcnt.get(d, 0)
        
        return Scnt==Tcnt

### Solution2 ###
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        sl, tl = [], []
        for c in s:
            sl.append(c)
        for c in t:
            tl.append(c) 
        sl.sort()
        tl.sort()
        
        if sl==tl:
            return True
        else:
            return False
