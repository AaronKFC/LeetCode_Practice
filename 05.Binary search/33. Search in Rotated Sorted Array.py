### Solution1 (NeetCode) ###
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1

        while l <= r:
            mid = (l + r) // 2
            if target == nums[mid]:
                return mid

            # left sorted portion
            if nums[l] <= nums[mid]:
                if target > nums[mid] or target < nums[l]:
                    l = mid + 1
                else:
                    r = mid - 1
            # right sorted portion
            else:
                if target < nums[mid] or target > nums[r]:
                    r = mid - 1
                else:
                    l = mid + 1
        return -1

### Solution2 (NeetCode) ###
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums)-1
        
        while l<=r:
            mid = l + (r-l)//2
            
            if nums[mid] == target:
                return mid
            
            # left sorted portion
            if nums[l] <= nums[mid]:
                if target <= nums[mid] and target >= nums[l]:
                    r = mid - 1
                else:
                    l = mid + 1
            else: # right sorted portion
                if target >= nums[mid] and target <= nums[r]:
                    l = mid + 1
                else:
                    r = mid - 1
        return -1

