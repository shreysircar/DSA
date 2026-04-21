//memoization
class Solution {
public:
bool isPalindrome(string s, int i,int j){
while(i<j){
    if(s[i]==s[j]){
        i++;  j--;
    }
    else{
        return false;}
}
return true;
}

int solve(string s, int i, vector<int> &dp){
    int n=s.length();
    if(i>=n){return -1;} //since we add 1 to the cuts, we return -1 when we reach the end of the string (since we added an extra 1)
    if(dp[i]!=-1){return dp[i];}
    int minCuts=INT_MAX;
for(int j=i;j<n;j++){
    if(isPalindrome(s,i,j)){
        int cuts=1 + solve(s,j+1,dp); //we make a cut after j pointer
        minCuts=min(minCuts,cuts);
    }
}
return dp[i]=minCuts;
}
    int minCut(string s) {
    int n=s.length();
    vector<int>dp(n,-1);
    return solve(s,0,dp);
    }
};

//bottom up
class Solution {
public:
bool isPalindrome(string &s, int i,int j){
while(i<j){
    if(s[i]==s[j]){
        i++;  j--;
    }
    else{
        return false;}
}
return true;
}

    int minCut(string s) {
    int n=s.length();
    vector<int>dp(n+1,-1);
    for(int i=n-1;i>=0;i--){
       int a=INT_MAX;
       dp[n]=-1;
       for(int j=i;j<n;j++){
        if(isPalindrome(s,i,j)){
            int cuts=1 + dp[j+1];
            a=min(a,cuts);
        }
       }
       dp[i]=a;
    }
    return dp[0];
    }
};