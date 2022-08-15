/*
    Given int array, return all unique triplets that sum to 0
    Ex. nums = [-1,0,1,2,-1,-4] -> [[-1,-1,2],[-1,0,1]]

    Sort, for each i, have j & k go outside in, check for 0 sums

    Time: O(n^2)
    Space: O(n)
*/

// Solution1 (My implementation)  (比NeetCode少一些step，但也是summit成功了，而且時間差不多)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int nlen = nums.size();
        if (nlen < 3) {
            return res;
        }
        
        sort(nums.begin(), nums.end()); //此step關鍵
        
        
        for (int i=0; i<nlen-2; i++) {
            if (i>0 && nums[i]==nums[i-1]) {  //搭配sort，此step才有用
                continue;
            }
            int first = nums[i];
            int l=i+1;
            int r=nlen-1;
            
            while (l<r) {
                int second = nums[l];
                int third = nums[r];
                int sum = first + second + third;
                if (sum > 0) {
                    r--;
                } else if (sum < 0) {
                    l++;
                } else {
                    res.push_back({first, second, third});
                    l++;
                    while (l<r && nums[l]==nums[l-1]) {  //此step也很關鍵
                        l++;
                    }
                }
            }
        }
        return res;
    }
};

// Solution2 (NeetCode) 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        int n = nums.size();
        if (n < 3) {
            return result;
        }
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }
            
            int j = i + 1;
            int k = n - 1;
            
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    result.push_back({nums[i], nums[j], nums[k]});
                    
                    while (j < k && nums[j] == nums[j + 1]) {
                        j++;
                    }
                    j++;
                    
                    while (j < k && nums[k - 1] == nums[k]) {
                        k--;
                    }
                    k--;
                }
            }
        }
        
        return result;
    }
};
