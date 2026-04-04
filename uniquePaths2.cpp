//memoization
class Solution {
public:
    int solve(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int m = grid.size();
        int n = grid[0].size();

        // out of bounds
        if (r >= m || c >= n) return 0;

        // obstacle
        if (grid[r][c] == 1) return 0;

        // destination
        if (r == m-1 && c == n-1) return 1;

        if (dp[r][c] != -1) return dp[r][c];

        int down = solve(r+1, c, grid, dp);
        int right = solve(r, c+1, grid, dp);

        return dp[r][c] = down + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(0, 0, grid, dp);
    }
};


//tabulation
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // start blocked
        if (grid[0][0] == 1) return 0;

        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // obstacle
                if (grid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }

                // skip start (already set)
                if (i == 0 && j == 0) continue;

                int up = 0, left = 0;

                if (i > 0) up = dp[i-1][j];
                if (j > 0) left = dp[i][j-1];

                dp[i][j] = up + left;
            }
        }

        return dp[m-1][n-1];
    }
};