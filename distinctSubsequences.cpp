class Solution {
public:
int solve(string &s, string &t, int i, int j,vector<vector<int>>&dp){
    if(j<0){return 1;}
    if(i<0){return 0;}
    if(dp[i][j]!=-1){return dp[i][j];}
    if(s[i]==t[j]){
        return dp[i][j]=solve(s,t,i-1,j-1,dp)+solve(s,t,i-1,j,dp);
    }
    else{
        return dp[i][j]=solve(s,t,i-1,j,dp);
    }
}
    int numDistinct(string s, string t) {
vector<vector<int>>dp(s.length(),vector<int>(t.length(),-1));
       return solve(s,t,s.length()-1,t.length()-1,dp); 
    }
};

//bottom up
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();

        vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));

        // base case: empty t
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // fill DP
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][m];
    }
};


//space optimized(1d array)
