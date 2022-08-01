
// Bit Operation implementation
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        
        for (int i=0; i<nums.size(); i++) {
            result = nums[i] ^ result;
        }
        return result;
    }
};

/////////////////////////////////////////
// unordered_set implementation
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> tmp;
        
        for (int i=0; i<nums.size(); i++) {
            if (tmp.find(nums[i]) == tmp.end()) {
                tmp.insert(nums[i]);
            } else {
                tmp.erase(nums[i]);
            }
        }
        return *tmp.begin();
    }
};
