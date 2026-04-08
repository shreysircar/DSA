class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        
        int s = 0;
        for(int num : nums) s += num;
        
        if(s % 2 != 0) return false;
        
        int target = s / 2;

        vector<bool> dp(target + 1, false);
        
        // base case
        dp[0] = true;

        for(int i = 0; i < n; i++) {
            int num = nums[i];
            
            for(int x = target; x >= num; x--) {
                dp[x] = dp[x] || dp[x - num];
            }
        }

        return dp[target];
    }
};