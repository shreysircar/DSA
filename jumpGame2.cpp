class Solution {
public:

int solve(vector<int>&nums,int idx,vector<int>&dp){
int n=nums.size();
if(idx>=n-1){return 0;}
if(dp[idx]!=-1){return dp[idx];}
int take=INT_MAX;
for(int i=1;i<=nums[idx];i++){
int step=solve(nums,idx+i,dp);
if(step!=INT_MAX){
 take=min(take,1+step); } 
}
return dp[idx]=take;
}
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
    return solve(nums,0,dp);    
    }
};