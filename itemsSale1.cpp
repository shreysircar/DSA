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

class Solution {
public:

    // solve(i, budgetLeft)
    // = maximum number of copies obtainable considering items from i onward
    //   when we still have budgetLeft money remaining.
    int solve(int i, vector<int>& freebie, vector<vector<int>>& items,
              int budgetLeft, int minPrice, vector<vector<int>>& dp) {

        int n = items.size();

        // Base case:
        // We have finished deciding which item types to activate.
        // Whatever budget remains should be spent on the cheapest item,
        // since every additional purchase gives exactly +1 copy.
        if (i == n) {
            return budgetLeft / minPrice;
        }

        // Memoization
        if (dp[i][budgetLeft] != -1)
            return dp[i][budgetLeft];

        int take = 0;

        // Option 1: Activate item i
        //
        // Activation means buying the FIRST copy of this item.
        // freebie[i] already contains:
        //   1 purchased copy + all free copies obtained from this activation.
        //
        // We then move to i+1 because the one-time activation bonus
        // can only be claimed once.
        if (items[i][1] <= budgetLeft) {
            take =
                solve(i + 1,
                      freebie,
                      items,
                      budgetLeft - items[i][1],   // pay activation cost
                      minPrice,
                      dp)
                + freebie[i];                    // gain activation reward
        }

        // Option 2: Skip activating item i
        int notTake =
            solve(i + 1,
                  freebie,
                  items,
                  budgetLeft,
                  minPrice,
                  dp);

        // Store and return best choice
        return dp[i][budgetLeft] = max(take, notTake);
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();

        // freebie[i] =
        // total copies obtained from activating item i once
        //
        // Start with 1 because buying the first copy itself
        // already gives one item.
        vector<int> freebie(n, 1);

        // dp[i][b]
        // = answer for state (i, b)
        vector<vector<int>> dp(n, vector<int>(budget + 1, -1));

        // Compute activation reward for every item.
        //
        // If factor[i] divides factor[j],
        // activating i gives one free copy of j.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (i != j &&
                    items[j][0] % items[i][0] == 0) {

                    freebie[i]++;
                }
            }
        }

        // Cheapest item price.
        //
        // After all activations are decided,
        // remaining budget is always spent on the cheapest item
        // because every extra purchase gives exactly +1 copy.
        int minPrice = INT_MAX;

        for (auto& x : items) {
            minPrice = min(minPrice, x[1]);
        }

        return solve(0,
                     freebie,
                     items,
                     budget,
                     minPrice,
                     dp);
    }
};