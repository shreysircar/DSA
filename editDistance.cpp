//pure recursion
class Solution {
public:
int solve(string &s1, string &s2, int i, int j){
    if(i>=s1.length()){
        return s2.length()-j;
    }
    if(j>=s2.length()){
        return s1.length()-i;
        }
    if(s1[i]==s2[j]){
        return solve(s1,s2,i+1,j+1);
    }
    else{
        int ins=1+solve(s1,s2,i,j+1);
        int del=1+solve(s1,s2,i+1,j);
        int rep=1+solve(s1,s2,i+1,j+1);
    return min(min(ins,del),rep);
    }
}
    int minDistance(string word1, string word2) {
        return solve(word1,word2,0,0);
    }
};




//memoization(LEFT->RIGHT)
class Solution {
public:
int solve(string &s1, string &s2, int i, int j,vector<vector<int>>&dp){
    if(i>=s1.length()){
        return s2.length()-j;
    }
    if(j>=s2.length()){
        return s1.length()-i;
        }
        if(dp[i][j]!=-1){return dp[i][j];}
    if(s1[i]==s2[j]){
        return dp[i][j]=solve(s1,s2,i+1,j+1,dp);
    }
    else{
        int ins=1+solve(s1,s2,i,j+1,dp);
        int del=1+solve(s1,s2,i+1,j,dp);
        int rep=1+solve(s1,s2,i+1,j+1,dp);
    return dp[i][j]=min(min(ins,del),rep);
    }
}
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length(),vector<int>(word2.length(),-1));
        return solve(word1,word2,0,0,dp);
    }
};

//Approach-1 (Recur + Memo, starting from m, n)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int t[501][501];
    int solve(string& s1, string& s2, int m, int n) {
        if(m == 0 || n == 0)
            return m+n;
        
        if(t[m][n] != -1)
            return t[m][n];
        
        if(s1[m-1] == s2[n-1])
            return t[m][n] = solve(s1, s2, m-1, n-1);
        else {
            int insertC  = 1 + solve(s1, s2, m, n-1);
            int deleteC  = 1 + solve(s1, s2, m-1, n);
            int replaceC = 1 + solve(s1, s2, m-1, n-1);
            
            return t[m][n] = min({insertC, deleteC, replaceC});
        }
        
    }
    
    int minDistance(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        memset(t, -1, sizeof(t));
        return solve(s1, s2, m, n);
    }
};

//bottom up (we can reverse (RIGHT ->LEFT) the above memoization code to get the bottom up code)
class Solution {
public:
    int editDistance(string s1, string s2, int m, int n) {
        vector<vector<int>> t(m+1, vector<int>(n+1));
        
        for(int i = 0; i<m+1; i++) {
            for(int j = 0; j<n+1; j++) {
                if(i == 0 || j == 0)
                    t[i][j] = i+j;
                else if(s1[i-1] == s2[j-1])
                    t[i][j] = t[i-1][j-1];
                else
                    t[i][j] = 1 + min({t[i][j-1], t[i-1][j], t[i-1][j-1]});
            }
        }
        return t[m][n];
    }
    int minDistance(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        
        return editDistance(s1, s2, m, n);
    }
};
