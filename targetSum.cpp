class Solution {
public:
int solve(vector<int>& nums,int index, int target,vector<vector<int>>&dp,int offset){
    int n=nums.size();
if(index == n) {
    return (target == 0) ? 1 : 0;
}
        if (target + offset < 0 || target + offset > 2*offset)
            return 0;
if(dp[index][target+offset]!=-1){return dp[index][target+offset];}
int plus=solve(nums,index+1,target-nums[index],dp,offset);
int minus=solve(nums,index+1,target+nums[index],dp,offset);
return dp[index][target+offset]=(plus+minus);
}


    int findTargetSumWays(vector<int>& nums, int target) {
                int sum=0;
        for(int i=0;i<nums.size();i++){sum+=nums[i];}
        vector<vector<int>>dp(nums.size(),vector<int>(2*sum+1,-1));

      return solve(nums,0,target,dp,sum);  
    }
};




/*
class Solution {
public:
    int solve(vector<int>& nums, int index, int target) {
        int n = nums.size();

        if (index == n) {
            return (target == 0) ? 1 : 0;
        }

        int plus = solve(nums, index+1, target - nums[index]);
        int minus = solve(nums, index+1, target + nums[index]);

        return plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, 0, target);
    }
};*/