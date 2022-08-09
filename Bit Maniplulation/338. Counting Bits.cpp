// solution 1
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            //                 i / 2      i % 2
            result[i] = result[i >> 1] + (i & 1);
        }
        return result;
    }
};

// Solution2
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp;
        dp.push_back(0);
               
        int offset = 1;
        for (int i=1; i<=n; i++) {
            if (offset*2 == i) {
                offset = i;
            }
            dp.push_back(1+dp[i-offset]);
        }
        return dp;
    }
};


