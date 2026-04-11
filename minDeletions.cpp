class Solution {
public:
int solve(string &s1,string &s2, int i, int j){
    if(i >= s1.size()) return s2.size() - j;
    if(j >= s2.size()) return s1.size() - i;
   if(s1[i]==s2[j]){return solve(s1,s2,i+1,j+1);}
   int left=1+solve(s1,s2,i+1,j);
   int right=1+solve(s1,s2,i,j+1);
   return min(left,right);
}
    int minDistance(string word1, string word2) {
        return solve(word1,word2,0,0);
    }
};

//memoization
class Solution {
public:
int solve(string &s1,string &s2, int i, int j, vector<vector<int>>&dp){
    if(i >= s1.size()) return s2.size() - j;
    if(j >= s2.size()) return s1.size() - i;
   if(s1[i]==s2[j]){return dp[i][j]=solve(s1,s2,i+1,j+1,dp);}
   if(dp[i][j]!=-1){return dp[i][j];}
   int left=1+solve(s1,s2,i+1,j,dp);
   int right=1+solve(s1,s2,i,j+1,dp);
   return dp[i][j]=min(left,right);
}
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length(),vector<int>(word2.length(),-1));
        return solve(word1,word2,0,0,dp);
    }
};