class Solution {
public:

    int solve(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int m = grid.size();
        int n = grid[0].size();

if(dp[r][c]!=-1){return dp[r][c];}

        // destination
        if (r == m-1 && c == n-1) {
            return grid[r][c];
        }

        // last row, can only go right
        if (r==m-1) {
            return dp[r][c]= grid[r][c]+solve(r,c+1,grid,dp);
        }
               else if (c==n-1) {           //last col, can only go down
            return dp[r][c]=grid[r][c]+solve(r+1,c,grid,dp);
        }

        int right = solve(r, c+1, grid,dp);
        int down = solve(r+1, c, grid,dp);

        return dp[r][c]=grid[r][c] + min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
      vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0, 0, grid, dp);
    }
};