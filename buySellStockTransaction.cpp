//memoization
class Solution {
public:
int solve(vector<int>& prices,int fee, int i,bool buy, vector<vector<int>>& dp){
    if(i>=prices.size()){return 0;}
    int profit=0;
    if(dp[i][buy]!=-1){return dp[i][buy];}
    if(buy){
        buy=0;
        int buyNow=solve(prices,fee,i+1,buy,dp)-prices[i];
        buy=1;
        int skip1=solve(prices,fee,i+1,buy,dp);
        profit=max(buyNow,skip1);
    }
    else{
        buy=1;
        int sellNow=solve(prices,fee,i+1,buy,dp)+prices[i]-fee;
        buy=0;
        int skip2=solve(prices,fee,i+1,buy,dp);
        profit=max(sellNow,skip2);
    }
    return  dp[i][buy]=profit;
}

    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
       return solve(prices,fee,0,1,dp); 
    }
};

//bottom up
  int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for(int i = n-1; i >= 0; i--){
            // buy = 1
            dp[i][1] = max(
                -prices[i] + dp[i+1][0],
                dp[i+1][1]
            );

            // buy = 0
            dp[i][0] = max(
                prices[i] - fee + dp[i+1][1],
                dp[i+1][0]
            );
        }

        return dp[0][1];
    }