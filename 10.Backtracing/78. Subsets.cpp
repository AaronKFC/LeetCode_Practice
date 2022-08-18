class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return result;
        }
    
private:
    vector<int> subset;
    vector<vector<int>> result;
    void dfs(int i, vector<int> nums) {
        if (i >= nums.size()) {
            result.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        dfs(i+1, nums);
        
        subset.pop_back();
        dfs(i+1, nums);
        
    }

};