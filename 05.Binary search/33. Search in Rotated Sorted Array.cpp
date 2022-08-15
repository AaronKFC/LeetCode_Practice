/*
    Given array after some possible rotation, find if target is in nums
    Ex. nums = [4,5,6,7,0,1,2] target = 0 -> 4 (value 0 is at index 4)

    Modified binary search, if low <= mid left sorted, else right sorted

    Time: O(log n)
    Space: O(1)
*/

// Solution1 (NeetCode)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        
        return -1;
    }
};

// Solution2 (NeetCode) 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        
        while (l<=r) {
            int mid = l + (r-l)/2;
            if (nums[mid]==target) {
                return mid;
            }
            
            // left sorted portion
            if (nums[l] <= nums[mid]) {
                if (target > nums[mid] or target < nums[l]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                } 
            } else { //right sorted portion
                if (target < nums[mid] or target > nums[r]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        return -1;
    }
};