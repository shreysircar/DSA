//recursion
class Solution {
public:
int solve(vector<int>&cuts,int l,int r){
    if(r-l<2){return 0;}
    int res=INT_MAX;
    for(int i=l+1;i<=r-1;i++){
        int cost= cuts[r]-cuts[l]+solve(cuts,l,i)+solve(cuts,i,r);
        res=min(res,cost);
    }
    return res;
}
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        return solve(cuts,0,cuts.size()-1);
    }
};

//memoization
class Solution {
public:
int solve(vector<int>&cuts,int l,int r,vector<vector<int>>&dp){
    if(r-l<2){return 0;}
    int res=INT_MAX;
    if(dp[l][r]!=-1){return dp[l][r];}
    for(int i=l+1;i<=r-1;i++){
        int cost= cuts[r]-cuts[l]+solve(cuts,l,i,dp)+solve(cuts,i,r,dp);
        res=min(res,cost);
    }
    return dp[l][r]=res;
}
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        vector<vector<int>>dp(cuts.size(),vector<int>(cuts.size(),-1));
        return solve(cuts,0,cuts.size()-1,dp);
    }
};

//bottom up
int minCost(int n, vector<int>& cuts) 
    {
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        int m=cuts.size();
        vector<vector<int>> dp(m,vector<int>(m,0));
//in memoization(recursion), l is running from 0 to cuts.size()-1
//and r is running from cuts.size()-1 to 0
//hence in tabulation,l will run from cuts.size()-1 to 0
//and r will run from 0 to cuts.size()-1
        for(int l=c-1;l>=0;l--)
        {
            for(int r=0;r<=c-1;r++)
            {
                if(r-l<2)
                {
                    dp[l][r]=0;
                    continue;
                }
                int ans=INT_MAX;
                for(int k=l+1;k<=r-1;k++)
                {
                    int temp=dp[l][k]+dp[k][r]+(cuts[r]-cuts[l]);
                    ans=min(ans,temp);
                }
                dp[l][r]=ans;
            }
        }
        return dp[0][m-1];
    }
};
