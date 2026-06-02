class Solution {
public:
    int solve(int i, vector<int>& freebie, vector<vector<int>>& items,
              int budgetLeft, int minPrice,vector<vector<int>>&dp) {
        int n = items.size();
        if (i == n) {
            return budgetLeft/minPrice;
        }
        if(dp[i][budgetLeft] != -1)
    return dp[i][budgetLeft];
        int take = 0;
        if (items[i][1] <= budgetLeft) {
            take = solve(i + 1, freebie, items, budgetLeft - items[i][1], minPrice,dp) +
                   freebie[i];  
        }
        int notTake = solve(i + 1, freebie, items, budgetLeft, minPrice,dp);
        return dp[i][budgetLeft]=max(take, notTake);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> freebie(n, 1);
        vector<vector<int>>dp(n,vector<int>(budget+1,-1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && (items[j][0] % items[i][0] == 0)) {
                    freebie[i]++;
                }
            }
        }
int minPrice=INT_MAX;
        for(auto &x:items){
minPrice=min(minPrice, x[1]);
        }
        return solve(0, freebie, items, budget, minPrice,dp);
    }
};
