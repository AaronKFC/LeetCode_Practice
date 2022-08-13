/*
    Given array of banana piles, guards are gone for h hours
    Return min int k such that can eat all banans within h
    Ex. piles = [3,6,7,11] h = 8 -> 4 (1@3, 2@6, 2@7, 3@11)

    Binary search, for each k count hours needed, store min

    Time: O(n x log m) -> n = # of piles, m = max # in a pile
    Space: O(1)
*/

// Solution1 (NeetCode)
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        
        int low = 1;
        int high = 0;
        for (int i = 0; i < n; i++) {
            high = max(high, piles[i]);
        }
        
        int result = high;
        
        while (low <= high) {
            int k = low + (high - low) / 2;
            long int hours = 0;
            for (int i = 0; i < n; i++) {
                hours += ceil((double) piles[i] / k);
                // hours += floor((double)piles[i] / k)+1;
            }
            if (hours <= h) {
                result = min(result, k);
                high = k - 1;
            } else {
                low = k + 1;
            }
        }
        
        return result;
    }
};


// Solution2 (My implementation)
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = *std::max_element(piles.begin(), piles.end());
        int l = 1;
        int res = r;
        cout << sizeof(long) << endl;
        cout << sizeof(int) << endl;
        
        while (l <= r) {
            int k = l + (r-l)/2;
            // int t = 0;
            long t = 0;  //注意要用long，才能避免某些test case的overflow問題。
            for (int i=0; i<piles.size(); i++) {
                t += piles[i]/k;
                if (piles[i]%k != 0) {
                    t++;
                }
            }
            // 以下這段在某些test case的錯誤待思考。
            if (t > h) {
                l=k+1;
            } else if (t < h) {
                r=k-1;
            } else {
                // cout << t << endl;
                res=k;
                break;
            }
        }
        return res;
    }
};
