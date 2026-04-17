//recursion
class Solution {
public:
bool isPred(string& curr, string& prev){
    int n = curr.length(); // longer
    int m = prev.length(); // shorter

    if(n - m != 1) return false;

    int i = 0, j = 0;

    while(i < n && j < m){
        if(curr[i] == prev[j]){
            i++;
            j++;
        } else {
            i++; // skip one char in curr
        }
    }

    return j == m;
}
int solve(vector<string>& words,int i,int prev){
int n=words.size();
if(i>=n){return 0;}
int take=0;
if(prev==-1 || isPred(words[i],words[prev])){
 take=1+solve(words,i+1,i);
}
int notTake=solve(words,i+1,prev);
return max(take,notTake);
}

static bool myFunc(string &word1, string &word2){
    return word1.length()<word2.length();
}

    int longestStrChain(vector<string>& words) {
     sort(begin(words),end(words),myFunc);
     return solve(words,0,-1);   
    }
};

//memoization
class Solution {
public:
bool isPred(string& curr, string& prev){
    int n = curr.length(); // longer
    int m = prev.length(); // shorter

    if(n - m != 1) return false;

    int i = 0, j = 0;

    while(i < n && j < m){
        if(curr[i] == prev[j]){
            i++;
            j++;
        } else {
            i++; // skip one char in curr
        }
    }

    return j == m;
}
int solve(vector<string>& words,int i,int prev,vector<vector<int>>&dp){
int n=words.size();
if(i>=n){return 0;}
if(dp[i][prev+1]!=-1){return dp[i][prev+1];}
int take=0;
if(prev==-1 || isPred(words[i],words[prev])){
 take=1+solve(words,i+1,i,dp);
}
int notTake=solve(words,i+1,prev,dp);
return max(take,notTake);
}

static bool myFunc(string &word1, string &word2){
    return word1.length()<word2.length();
}

    int longestStrChain(vector<string>& words) {
     sort(begin(words),end(words),myFunc);
     vector<vector<int>>dp(words.size(),vector<int>(words.size(),-1));
     return solve(words,0,-1,dp);   
    }
};

//bottom up
class Solution {
public:
bool isPred(string& curr, string& prev){
    int n = curr.length(); // longer
    int m = prev.length(); // shorter

    if(n - m != 1) return false;

    int i = 0, j = 0;

    while(i < n && j < m){
        if(curr[i] == prev[j]){
            i++;
            j++;
        } else {
            i++; // skip one char in curr
        }
    }

    return j == m;
}

static bool myFunc(string &word1, string &word2){
    return word1.length()<word2.length();
}

  int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(),
            [](string &a, string &b){
                return a.size() < b.size();
            });

        int n = words.size();
        vector<int> dp(n, 1);

        int maxLen = 1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(isPred(words[i], words[j])){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }

        return maxLen;
    }
};
