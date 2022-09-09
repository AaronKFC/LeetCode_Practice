/*
    Given a matrix, return all elements in spiral order

    Set up boundaries, go outside in CW: top->right->bottom->left

    Time: O(m x n)
    Space: O(m x n)
*/

// Solution1 (My implementation) similar to python method of NeetCode.
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0;
        int right = matrix[0].size();
        int top = 0;
        int bottom = matrix.size();
        vector<int> res;
        
        while (left<right && top<bottom) {
            for (int i=left; i<right; i++) {
                res.push_back(matrix[top][i]);
            }
            top++;
            
            for (int j=top; j<bottom; j++) {
                res.push_back(matrix[j][right-1]);
            }
            right--;
            
            if (!(left<right && top<bottom)) break;
            
            for (int i=right-1; i>=left; i--) {
                res.push_back(matrix[bottom-1][i]);
            }
            bottom--;
            
            for (int j=bottom-1; j>=top; j--) {
                res.push_back(matrix[j][left]);
            }
            left++;
        }
        
        return res;
    }
};


// Solution2 (NeetCode)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0;
        int top = 0;
        int right = matrix[0].size() - 1;
        int bottom = matrix.size() - 1;
        
        vector<int> result;
        
        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; j++) {
                result.push_back(matrix[top][j]);
            }
            top++;
            
            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;
            
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    result.push_back(matrix[bottom][j]);
                }
            }
            bottom--;
            
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
            }
            left++;
        }
        
        return result;
    }
};