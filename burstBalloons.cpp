//recursion
class Solution {
public:
    int solve(vector<int>& nums, int l, int r) {
        // base case: no balloon between l and r
        if (r - l <= 1) return 0;

        int ans = 0;

        // try every k as the LAST balloon to burst
        for (int k = l + 1; k < r; k++) {

            int coins =
                solve(nums, l, k) +        // left part
                solve(nums, k, r) +        // right part
                nums[l] * nums[k] * nums[r]; // last burst

            ans = max(ans, coins);
        }

        return ans;
    }

    int maxCoins(vector<int>& nums) {
        // add boundaries
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        return solve(nums, 0, nums.size() - 1);
    }
};

//memoization
class Solution {
public:
    int solve(vector<int>& nums, int l, int r, vector<vector<int>>& dp) {
        if (r - l <= 1) return 0;

        if (dp[l][r] != -1) return dp[l][r];

        int ans = 0;

        for (int k = l + 1; k < r; k++) {
            int coins =
                solve(nums, l, k, dp) +
                solve(nums, k, r, dp) +
                nums[l] * nums[k] * nums[r];

            ans = max(ans, coins);
        }

        return dp[l][r] = ans;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(nums, 0, n - 1, dp);
    }
};

//bottom up
int maxCoins(vector<int>& nums) {
    int n = nums.size();

    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    int m = nums.size();

    vector<vector<int>> dp(m, vector<int>(m, 0));

    // l = left boundary
    // r = right boundary
    for(int l = m - 2; l >= 1; l--){
        for(int r = l; r <= m - 2; r++){

            int maxi = 0;

            // k = last balloon to burst
            for(int k = l; k <= r; k++){

                int coins =
                    nums[l-1] * nums[k] * nums[r+1] +
                    dp[l][k-1] +
                    dp[k+1][r];

                maxi = max(maxi, coins);
            }

            dp[l][r] = maxi;
        }
    }

    return dp[1][m-2];
}