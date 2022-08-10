// Solution1 (My method)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> stats;
        vector<vector<int>> freq(n+1);
        
        for (int i=0; i<n; i++) {
            if (stats.find(nums[i]) != stats.end()) {
                stats[nums[i]]++;
            } else {
                stats.insert({nums[i], 1});
            }
        }
                
        unordered_map<int,int>::iterator iter;
        for (iter=stats.begin(); iter!=stats.end(); iter++) {
        // for (auto iter=stats.begin(); iter!=stats.end(); iter++) {
            freq[iter->second].push_back(iter->first);
        }
        
        vector<int> res;
        for (int i=freq.size()-1; i>=0; i--) {
            for (int j=0; j<freq[i].size(); j++) {
                res.push_back(freq[i][j]);
            }
            // if (!freq.empty()) {
            //     res.insert(res.end(), freq[i].begin(), freq[i].end());
            // }
            if (res.size() == k) {
                break;
            }
        }
        return res;
    }
};


// Solution2 (NeetCode better method)
// Time: O(n)
// Space: O(n)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
        }
        
        vector<vector<int>> buckets(n + 1);
        for (auto it = m.begin(); it != m.end(); it++) {
            buckets[it->second].push_back(it->first);
        }
        
        vector<int> result;
        
        for (int i = n; i >= 0; i--) {
            if (result.size() >= k) {
                break;
            }
            if (!buckets[i].empty()) {
                result.insert(result.end(), buckets[i].begin(), buckets[i].end());
            }
        }
        
        return result;
    }
};


// Solution3 (NeetCode priority_queue method)
/*
    Given an integer array nums & an integer k, return the k most frequent elements
    Ex. nums = [1,1,1,2,2,3] k = 2 -> [1,2], nums = [1] k = 1 -> [1]
    
    Heap -> optimize w/ freq map & bucket sort (no freq can be > n), get results from end
*/

// Time: O(n log k)
// Space: O(n + k)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto it = m.begin(); it != m.end(); it++) {
            pq.push({it->second, it->first});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};

