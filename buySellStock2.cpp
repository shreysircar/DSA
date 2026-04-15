//pure recursion
class Solution {
public:
int solve(vector<int>& prices,int i, bool buy){
    if(i>=prices.size()){return 0;}
    int profit=0;
if(buy){
    buy=0;
    int buyNow=solve(prices,i+1,buy)-prices[i];
    buy=1;
    int skip1=solve(prices,i+1,buy);
    profit=max(buyNow,skip1);
}
else{
    buy=1;
    int sellNow=prices[i]+solve(prices,i+1,buy);
    buy=0;
    int skip2=solve(prices,i+1,buy);
    profit=max(sellNow,skip2);
}
return profit;
}
    int maxProfit(vector<int>& prices) {
      return solve(prices,0,1);  
    }
};

//memoization
class Solution {
public:
int solve(vector<int>& prices,int i, bool buy,vector<vector<int>>&dp){
    if(i>=prices.size()){return 0;}
    int profit=0;
    if(dp[i][buy]!=-1){return dp[i][buy];}
if(buy){
    buy=0;
    int buyNow=solve(prices,i+1,buy,dp)-prices[i];
    buy=1;
    int skip1=solve(prices,i+1,buy,dp);
    profit=max(buyNow,skip1);
}
else{
    buy=1;
    int sellNow=prices[i]+solve(prices,i+1,buy,dp);
    buy=0;
    int skip2=solve(prices,i+1,buy,dp);
    profit=max(sellNow,skip2);
}
return dp[i][buy]= profit;
}
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
      return solve(prices,0,1,dp);  
    }
};