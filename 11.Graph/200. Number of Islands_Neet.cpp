/*
    Given grid where '1' is land & '0' is water, return # of islands

    DFS, set visited land to '0' to not visit it again, count islands

    Time: O(m x n)
    Space: O(m x n)
*/

// Solution1 (NeetCode)
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rowN = grid.size();
        int colN = grid[0].size();
        int islandN = 0;
        
        for (int i=0; i<rowN; i++) {
            for (int j=0; j<colN; j++) {
                if (grid[i][j]=='1') {
                    dfs(grid, i, j, rowN, colN);
                    islandN++;
                }
            }
        }
        return islandN;
    }
private:
    void dfs(vector<vector<char>>& grid, int i, int j, int rowN, int colN) {
        if (i<0 || j<0 || i>=rowN || j>=colN || grid[i][j]=='0') {
            return;
        }
        
        grid[i][j] = '0';  //非常重要的一步，就不需要做visited的unordered_set
        dfs(grid, i, j-1, rowN, colN);
        dfs(grid, i, j+1, rowN, colN);
        dfs(grid, i-1, j, rowN, colN);
        dfs(grid, i+1, j, rowN, colN);
    }
};


// Solution2 (My implementation) similar to NeetCode.
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int ROW = grid.size();
        int COL = grid[0].size();
        for (int i=0; i<ROW; i++) {
            for (int j=0; j<COL; j++) {
                if (grid[i][j] == '1') {
                    res += dfs(grid, i, j, ROW, COL);
                }
            }
        }
        return res;
    }
private:
    int dfs(vector<vector<char>>& grid, int i, int j, int ROW, int COL) {
        if (i<0 || j<0 || i>=ROW || j>=COL || grid[i][j] == '0') {
            return NULL;
        }
        grid[i][j] = '0';
        dfs(grid, i+1, j, ROW, COL);
        dfs(grid, i, j+1, ROW, COL);
        dfs(grid, i-1, j, ROW, COL);
        dfs(grid, i, j-1, ROW, COL);
        return 1;
    }
};