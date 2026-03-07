#include <bits/stdc++.h>
using namespace std;
/*
//recursion
    int change(int amount, vector<int>& coins) {
if(amount==0){return 1;}
      return solve(coins.size()-1,amount,coins);
    }

    int solve(int i,int amount,vector<int>& coins){
    if(i==0){
      if(amount%coins[i]==0){
        return 1;
      }
      else{
        return 0;
      }
    }
      int select=0;
      if(coins[i]<=amount){
       select=solve(i,amount-coins[i],coins);}
      int notselect=solve(i-1,amount,coins);
      return select+notselect;
    }

*/

/*
//memoization
vector<vector<int>>dp;

  int solve(int i,int amount,vector<int>& coins){
    if(amount==0){return 1;}
    if(i==0){
      if(amount%coins[i]==0){
        return 1;
      }
      else{
        return 0;
      }
    }
    if(dp[i][amount]!=-1){return dp[i][amount];}
      int select=0;
      if(coins[i]<=amount){
       select=solve(i,amount-coins[i],coins);}
      int notselect=solve(i-1,amount,coins);
      return dp[i][amount]=select+notselect;
    }

 int change(int amount, vector<int>& coins) {
int n=coins.size();
dp.assign(n,vector<int>(amount+1,-1));
      return solve(coins.size()-1,amount,coins);
    }

    */

    int change(int amount, vector<int>& coins) {
    int n = coins.size();

    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    // Base case: using only coins[0]
    for (int a = 0; a <= amount; a++) {
        if (a % coins[0] == 0)
            dp[0][a] = 1;
    }

    // Fill the DP table
    for (int i = 1; i < n; i++) {
        for (int a = 0; a <= amount; a++) {
            int notselect = dp[i - 1][a];
            int select = 0;

            if (coins[i] <= a) {
                select = dp[i][a - coins[i]];
            }

            dp[i][a] = select + notselect;
        }
    }

    return dp[n - 1][amount];
}


int main(){
vector<int> nums={1,2,5};
cout<<change(5,nums);
  return 0;}
