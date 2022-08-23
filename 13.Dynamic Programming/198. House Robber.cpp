/*
    Given int array, return max amount can rob (can't rob adjacent houses)
    Ex. nums = [1,2,3,1] -> 4, rob house 1 then house 3: 1 + 3 = 4

    Recursion w/ memoization -> DP, rob either 2 away + here, or 1 away
    Recurrence relation: robFrom[i] = max(robFrom[i-2] + nums[i], robFrom[i-1])

    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1=0;
        int rob2=0;
        
        for (int i=0; i<nums.size(); i++) {
            int temp = max(nums[i]+rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
};