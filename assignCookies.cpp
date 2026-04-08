class Solution {
public:
int solve(vector<int>& g, vector<int>& s, int i, int j,int cnt){
        int children=g.size();
        int cookies=s.size();
        if(i>=children || j>=cookies){return cnt;}
        if(s[j]>=g[i]){return  solve(g,s,i+1,j+1,cnt+1);}  //content child 
        else {return solve(g,s,i,j+1,cnt);}  //non content kid
}

    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
      return solve(g,s,0,0,0);
    }
};