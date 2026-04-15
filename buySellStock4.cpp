class Solution {
public:
int solve(int k,vector<int>&prices, int i, bool buy, int cnt, vector<vector<vector<int>>>& dp){
if(cnt==k){return 0;}
if(i>=prices.size()){return 0;}
int profit=0;
if(dp[i][buy][cnt]!=-1){return dp[i][buy][cnt];}
if(buy){
    buy=0;
    int buyNow=solve(k,prices,i+1,buy,cnt,dp)-prices[i];
    buy=1;
    int skip1=solve(k,prices,i+1,buy,cnt,dp);
profit=max(buyNow,skip1);
}
else{
    buy=1;
    int sellNow=solve(k,prices,i+1,buy,cnt+1,dp)+prices[i];
    buy=0;
    int skip2=solve(k,prices,i+1,buy,cnt,dp);
    profit=max(sellNow,skip2);
}
return dp[i][buy][cnt]=profit;
}
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k, -1)));
      return solve(k,prices,0,1,0,dp);  
    }
};