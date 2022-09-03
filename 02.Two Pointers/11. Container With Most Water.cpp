/*
    Given array of heights, find max water container can store
    Ex. height = [1,8,6,2,5,4,8,3,7] -> 49, (8 - 1) x min(8, 7)

    2 pointers outside in, greedily iterate pointer w/ lower height

    Time: O(n)
    Space: O(1)
*/

// O(n^2)的brute force法不符合。
// 以下是O(n)的解法
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int maxA=0;
        
        while(l<r) {
            int area = (r-l) * min(height[l], height[r]);
            maxA = max(maxA, area);
            
            if(height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        
        return maxA;
    }
};