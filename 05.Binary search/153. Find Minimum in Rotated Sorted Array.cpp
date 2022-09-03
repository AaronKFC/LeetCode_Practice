/*
    Given sorted array after some rotation, find min value
    Ex. nums = [3,4,5,1,2] -> 1, nums = [4,5,6,7,0,1,2] -> 0

    Binary search + ensuring we never disqualify possible min value

    Time: O(log n)
    Space: O(1)
*/

// Solution1 (implementation)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int res = nums[0];
        int l = 0;
        int r = nums.size()-1;
        
        while (l<=r) {
            if (nums[l] < nums[r]) {
                res = min(res, nums[l]);
                break;
            }
            
            int m = l + (r-l)/2;
            res = min(res, nums[m]);
            if (nums[m] >= nums[l]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return res;
    }
};



// Solution2 (NeetCode)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        // not low <= high since not searching for target
        while (low < high) {
            int mid = low + (high - low) / 2;
            // ex. [3,4,5,6,7,8,9,1,2], mid = 4, high = 8
            // nums[mid] > nums[high], min must be right
            if (nums[mid] > nums[high]) {
                // never consider mid bc know for sure not min
                low = mid + 1;
            // ex. [8,9,1,2,3,4,5,6,7], mid = 4, high = 8
            // nums[mid] <= nums[right], min must be left
            } else {
                // consider mid still bc could be min
                high = mid;
            }
        }
        
        // low lands on correct value, never disqualified mins
        return nums[low];
    }
};