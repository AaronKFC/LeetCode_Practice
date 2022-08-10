### Solution1 (NeetCode) ###
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        l, r = 0, len(nums)-1
        
        while l<r:
            curSum = nums[l] + nums[r]
            
            if curSum < target:
                l+=1
            elif curSum > target:
                r-=1
            else:
                return [l+1, r+1]




