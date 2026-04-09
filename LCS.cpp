//pure recursion
/*
class Solution {
public:
int solve(string text1, string text2, int i, int j){
if(i>=text1.size() || j>=text2.size()){return 0;}
if(text1[i]==text2[j]){return 1+ solve(text1,text2,i+1,j+1);}
else{
    return max(solve(text1,text2,i+1,j), solve(text1,text2,i,j+1));
}
}

    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1,text2,0,0);
    }
};
*/


//memoization
/*
class Solution {
public:
int solve(string text1, string text2, int i, int j,vector<vector<int>> &dp){
if(i>=text1.size() || j>=text2.size()){return 0;}
if(dp[i][j]!=-1){return dp[i][j];}
if(text1[i]==text2[j]){return dp[i][j]=1+ solve(text1,text2,i+1,j+1,dp);}
else{
    return dp[i][j]=max(solve(text1,text2,i+1,j,dp), solve(text1,text2,i,j+1,dp));
}
}

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        return solve(text1,text2,0,0,dp);
    }
};*/

//bottom up
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            if(text1[i] == text2[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
            } else {
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

    return dp[0][0];
}

//print LCS
string printLCS(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    // Step 1: Fill DP
    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            if(text1[i] == text2[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
            } else {
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

    // Step 2: Backtrack
    int i = 0, j = 0;
    string ans = "";

    while(i < n && j < m){
        if(text1[i] == text2[j]){
            ans += text1[i];
            i++;
            j++;
        }
        else if(dp[i+1][j] > dp[i][j+1]){
            i++;
        }
        else{
            j++;
        }
    }

    return ans;
}