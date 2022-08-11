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
        
        grid[i][j] = '0';
        dfs(grid, i, j-1, rowN, colN);
        dfs(grid, i, j+1, rowN, colN);
        dfs(grid, i-1, j, rowN, colN);
        dfs(grid, i+1, j, rowN, colN);
    }
};