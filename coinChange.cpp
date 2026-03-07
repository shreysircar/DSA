#include <bits/stdc++.h>
using namespace std;
/*
//recursion
int solve(int i,vector<int>& coins, int amount) {
    if (i == 0){
      if(amount%coins[i]==0){
        return amount/coins[i];
      }
      else{return 1e9;}
    } //base case

int notTake=0+solve(i-1,coins,amount);
int Take=1e9;
if(coins[i]<=amount){
  Take=1+solve(i,coins,amount-coins[i]);}
  return min(Take,notTake);
}

int coinChange(vector<int>& coins, int amount) {
return solve(coins.size()-1,coins,amount);
}
*/

/*
//memoization
int solve(int i, vector<int>& coins, int amount, vector<vector<int>>& dp) {
    // base case
    if (i == 0) {
        if (amount % coins[0] == 0)
            return amount / coins[0];
        else
            return 1e9;
    }

    // memoization check
    if (dp[i][amount] != -1)
        return dp[i][amount];

    int notTake = solve(i - 1, coins, amount, dp);

    int take = 1e9;
    if (coins[i] <= amount) {
        take = 1 + solve(i, coins, amount - coins[i], dp);
    }

    // store and return
    return dp[i][amount] = min(take, notTake);
}

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();

    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

    int res = solve(n - 1, coins, amount, dp);
    return (res >= 1e9 ? -1 : res);
}
*/

//tabulation
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    const int INF = 1e9;

    vector<vector<int>> dp(n, vector<int>(amount + 1, INF));

    // Base case: using only coin[0] row
    for (int a = 0; a <= amount; a++) {
        if (a % coins[0] == 0)
            dp[0][a] = a / coins[0];
    }

    // Fill the DP table
    for (int i = 1; i < n; i++) {
        for (int a = 0; a <= amount; a++) {
            int notTake = dp[i - 1][a];

            int take = INF;
            if (coins[i] <= a) {
                take = 1 + dp[i][a - coins[i]];
            }

            dp[i][a] = min(take, notTake);
        }
    }

    int ans = dp[n - 1][amount];
    return (ans >= INF ? -1 : ans);
}




int main(){
vector<int> nums={1,2,5};
cout<<coinChange(nums,11);
  return 0;}
