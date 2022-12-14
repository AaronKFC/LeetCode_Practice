// Solution1 (NeetCode)

/*
    Given a 1-indexed sorted int array & target:
    Return indices (added by 1) of 2 nums that add to target

    2 pointers, outside in, iterate i/j if sum is too low/high

    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        vector<int> res;
        
        while (l<r) {
            int curSum = nums[l] + nums[r];
            if (curSum < target) {
                l++;
            } else if (curSum > target) {
                r--;
            } else {
                res.push_back(l+1);
                res.push_back(r+1);
                break;
            }
        }
        return res;
    }
};
