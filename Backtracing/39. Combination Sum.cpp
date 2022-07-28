class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // sort(candidates.begin(), candidates.end()); //若input已sorted，則可有可無
        // dfs(candidates, target, 0, this->totSum);
        dfs(candidates, target, 0, totSum);
        return result;
    }
private:
    vector<vector<int>> result;
    vector<int> combn;
    int totSum=0;
    void dfs(vector<int>& candidates, int target, int i, int totSum) {
        if(totSum == target) {
            result.push_back(combn);
            return;
        }
        if(i >= candidates.size() || totSum > target) {
            return;
        }
        
        combn.push_back(candidates[i]);
        dfs(candidates, target, i, totSum+candidates[i]);
        
        combn.pop_back();
        dfs(candidates, target, i+1, totSum);
        return;
    }
};