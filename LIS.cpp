//pure recursion
class Solution {
public:
int solve(vector<int>&nums,int i, int prev){
if(i>=nums.size()){return 0;}
int take=INT_MIN;
int notTake=solve(nums,i+1,prev);
    if(prev==-1 || nums[prev]<nums[i]){
        prev=i;
     take=1+solve(nums,i+1,prev);}

return max(take,notTake);
}
    int lengthOfLIS(vector<int>& nums) {
      return solve(nums,0,-1);
    }
};

//BOTTOM UP
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1); // dp[i] = LIS ending at i
        int maxi = 1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
}; 