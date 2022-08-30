/*
    Given unsorted array, return length of longest consecutive sequence
    Ex. nums = [100,4,200,1,3,2] -> 4, longest is [1,2,3,4]

    Store in hash set, only check for longer seq if it's the beginning

    Time: O(n)
    Space: O(n)
*/

// Solution1 (My implementation) similar to python method of NeetCode
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;
        
        for (int i=0; i<nums.size(); i++) {
            if (numSet.find(nums[i]-1) == numSet.end()) {
                int length = 0;
                while (numSet.find(nums[i]+length) != numSet.end()) {
                    length++;
                }
                longest = max(longest, length);
            }
        }
        
        return longest;
    }
};


// Solution2 (NeetCode)  much faster
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(), nums.end());
        int longest = 0;
        for(auto &n: s){
            //if this is the start of the sequence
            if(!s.count(n - 1)){
                int length = 1; 
                while(s.count(n + length))
                    ++length;
                longest = max(longest, length);
            } 

        }
        return longest;
    }
};