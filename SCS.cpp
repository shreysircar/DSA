//pure recursion approach
class Solution {
public:
string solve(string &str1,string str2,int i, int j){
int n=str1.length();
int m=str2.length();
        if(i >= n) return str2.substr(j);
        if(j >= m) return str1.substr(i);
if(str1[i]==str2[j]){
    return str1[i] + solve(str1,str2,i+1,j+1);
}
string one = str1[i] + solve(str1,str2,i+1,j);
string two = str2[j] + solve(str1,str2,i,j+1);
return (one.length()<two.length())? one : two;
}

    string shortestCommonSupersequence(string str1, string str2) {
        return solve(str1,str2,0,0);
    }
};

//memoization approach
class Solution {
public:
    string solve(string &str1, string &str2, int i, int j, vector<vector<string>> &dp) {
        int n = str1.length();
        int m = str2.length();

        if(i >= n) return str2.substr(j);
        if(j >= m) return str1.substr(i);

        if(dp[i][j] != "") return dp[i][j];

        if(str1[i] == str2[j]) {
            return dp[i][j] = str1[i] + solve(str1, str2, i+1, j+1, dp);
        }

        string one = str1[i] + solve(str1, str2, i+1, j, dp);
        string two = str2[j] + solve(str1, str2, i, j+1, dp);

        return dp[i][j] = (one.length() < two.length()) ? one : two;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();

        vector<vector<string>> dp(n, vector<string>(m, ""));

        return solve(str1, str2, 0, 0, dp);
    }
};

//bottom up + printing output string
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // Base cases
        for(int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        for(int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }

        // Fill DP (forward)
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(str1[i-1] == str2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        // 🔥 Reconstruct SCS
        int i = n, j = m;
        string ans = "";

        while(i > 0 && j > 0) {
            if(str1[i-1] == str2[j-1]) {
                ans += str1[i-1];
                i--; j--;
            }
            else if(dp[i-1][j] < dp[i][j-1]) {
                ans += str1[i-1];
                i--;
            } else {
                ans += str2[j-1];
                j--;
            }
        }

        // remaining characters
        while(i > 0) {
            ans += str1[i-1];
            i--;
        }
        while(j > 0) {
            ans += str2[j-1];
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};