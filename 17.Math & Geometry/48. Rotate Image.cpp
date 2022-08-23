/*
    Given a 2D image matrix, rotate image 90 deg CW

    Transpose + reflect (rev on diag then rev left to right)

    Time: O(n^2)
    Space: O(1)
*/

// Solution1 (NeetCode)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};


// Solution2 (My implementation1) similar to NeetCode python method
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l = 0;
        int r = matrix[0].size()-1;
        
        while (l < r) {
            // cout << "l=" << l << endl;
            // cout << "r=" << r << endl;
            int loopN = r-l;
            for (int i=0; i<loopN; i++) {
                int t=l;
                int b=r;
                // cout << "t=" << t << endl;
                
                // bl to tl //
                int temp = matrix[t][l+i];
                matrix[t][l+i] = matrix[b-i][l];
                
                // br to bl //
                matrix[b-i][l] = matrix[b][r-i];
                
                // tr to br //
                matrix[b][r-i] = matrix[t+i][r];
                
                // tl to tr //
                matrix[t+i][r] = temp;
            }
            l++;
            r--;
        }
        // return matrix;  //not necessary
    }
};


// Solution3 (My implementation2) 逆時鐘 swap 三次
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l = 0;
        int r = matrix[0].size()-1;
        
        while (l < r) {
            // cout << "l=" << l << endl;
            // cout << "r=" << r << endl;
            int loopN = r-l;
            for (int i=0; i<loopN; i++) {
                int t=l;
                int b=r;
                // cout << "t=" << t << endl;
                
                // bl to tl //
                swap(matrix[t][l+i], matrix[b-i][l]);
                
                // br to bl //
                swap(matrix[b-i][l],matrix[b][r-i]);
                
                // tr to br //
                swap(matrix[b][r-i], matrix[t+i][r]);
                
            }
            l++;
            r--;
        }
        // return matrix;  //not necessary
    }
};