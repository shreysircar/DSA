class Solution {
public:

int solve(vector<int>&arr,int i, int k,vector<int>&t){
    if(i>=arr.size()){return 0;}
    int take=-1;
    if(t[i]!=-1){return t[i];}
    int currMax=-1;
    for(int j=i;j<arr.size() && j-i+1<=k;j++){
     currMax=max(currMax,arr[j]);
     take=max(take,((j-i+1)*currMax)+solve(arr,j+1,k,t));
         }
         return t[i]=take;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>t(arr.size(),-1);
        return solve(arr,0,k,t);
    }
};

//bottom up
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);  // dp[i] = max sum from i → end

        // Build from back
        for (int i = n - 1; i >= 0; i--) {
            int currMax = 0;
            int best = 0;

            // Try partitions starting at i
            for (int j = i; j < n && (j - i + 1) <= k; j++) {
                currMax = max(currMax, arr[j]);

                int sum = (j - i + 1) * currMax + dp[j + 1];
                best = max(best, sum);
            }

            dp[i] = best;
        }

        return dp[0];
    }
};