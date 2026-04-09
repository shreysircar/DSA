class Solution{
  public:
  int solve(vector<int> &price,int i, int rodLen,vector<vector<int>> &dp){
   int p=price.size();
    if(rodLen==0){
    return 0;}
    if(i>=p){return INT_MIN;}
    if(dp[i][rodLen]!=-1){return dp[i][rodLen];}
    int take=INT_MIN;
      if(rodLen >= (i+1)){
          int temp = solve(price, i, rodLen-(i+1),dp);
          if(temp != INT_MIN)
              take = price[i] + temp;
      }
    int notTake=solve(price,i+1,rodLen,dp);
    return dp[i][rodLen]= max(take,notTake);
  }

    int rodCutting(vector<int> price, int n) {
        vector<vector<int>> dp(price.size(),vector<int>(n+1,-1));
     return solve(price,0,n,dp);
    }
};
