class Solution {
public:
int M=1e9+7;
typedef long long ll;
ll power(ll base, ll exp){
    if(exp==0){return 1;}

    ll half=power(base,exp/2);
    ll res=(half*half)%M;
    if(exp%2==1){res=(res*base)%M;}
    return res;
}
int getMaxDepth(unordered_map<int,vector<int>>&adj, int node, int parent){
    int d=0;
    for(int &ngbr:adj[node]){
        if(ngbr==parent){continue;}
        d=max(d,getMaxDepth(adj,ngbr,node)+1);
    }
    return d;
}

    int assignEdgeWeights(vector<vector<int>>& edges) {
unordered_map<int,vector<int>>adj;
for(auto &edge: edges){
    int u=edge[0];
    int v=edge[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int d=getMaxDepth(adj,1,-1);  //O(n)
return power(2,d-1);//O(log(d)

    }

};