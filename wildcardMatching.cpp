//pure recursion
class Solution {
public:
bool solve(string &s,string &p, int i, int j){

    if(i>=s.length() && j>=p.length()) return true;

    if(j>=p.length()) return false;

    if(i>=s.length()){
        while(j<p.length() && p[j]=='*') j++;
        return j==p.length();
    }

    if(s[i]==p[j] || p[j]=='?'){
        return solve(s,p,i+1,j+1);
    }

    if(p[j]=='*'){
    bool matchZero=solve(s,p,i,j+1);
    bool matchOther=solve(s,p,i+1,j);
        return matchZero || matchOther;
    }

    return false;
}

bool isMatch(string s, string p) {
    return solve(s,p,0,0); 
}
};

//memoization
class Solution {
public:
bool solve(string &s,string &p, int i, int j, vector<vector<int>>&dp){
    if(i>=s.length() && j>=p.length()){
        return true;
    }
    else if(i>=s.length()){
     while(j<p.length() && p[j]=='*'){
        j++;
     }
     return j==p.length();
     }
    else if(j>=p.length()){
    return false;
    }

    if(dp[i][j]!=-1){return dp[i][j];}

 if(s[i]==p[j] || p[j]=='?'){
    return dp[i][j]=solve(s,p,i+1,j+1,dp);}

else if(p[j]=='*'){
    bool matchZero=solve(s,p,i,j+1,dp);
    bool matchOther=solve(s,p,i+1,j,dp);
        return dp[i][j]=matchZero || matchOther;
}
return false;
}

    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.length(), vector<int>(p.length(),-1));
       return solve(s,p,0,0,dp); 
    }
};