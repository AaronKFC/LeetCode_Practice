
### Bit Operation implementation ###
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        unordered_set<int> tmp;
        
        for (int i=0; i<nums.size)


### Hash map implementation ###
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        tmp = []
        
        for n in nums:
            if n not in tmp:
                tmp.append(n)
            else:
                tmp.remove(n)
        
        return tmp[0]

