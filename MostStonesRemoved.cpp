class Solution {
public:

void dfs(vector<vector<int>>& stones, vector<bool>&vis,int index){
    vis[index]=true;
for(int i=0;i<stones.size();i++){
    int r=stones[index][0];
    int c=stones[index][1];
    if(vis[i]==false && (stones[i][0]==r || stones[i][1]==c)){
        dfs(stones,vis,i);
    }
}
}
    int removeStones(vector<vector<int>>& stones) {
       int n=stones.size();
       vector<bool>vis(n,false);
       int groups=0;
       for(int i=0;i<n;i++){
        if(vis[i]==true){
            continue;
        }
        dfs(stones,vis,i);
        groups++;
       } 
    return n-groups;
    }

}; 