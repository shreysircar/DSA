#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool dfs(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& inRec) {

    visited[u] = true;
    inRec[u] = true;

    for(int v : adj[u]) {

        if(!visited[v] && dfs(v, adj, visited, inRec))
            return true;

        else if(inRec[v])
            return true;
    }

    inRec[u] = false;
    return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

    vector<vector<int>> adj(numCourses);

    for(auto &p : prerequisites) {
        int a = p[0];
        int b = p[1];
        adj[b].push_back(a);   // b → a
    }

    vector<bool> visited(numCourses,false);
    vector<bool> inRec(numCourses,false);

    for(int i=0;i<numCourses;i++){
        if(!visited[i] && dfs(i,adj,visited,inRec))
            return false;   // cycle exists
    }

    return true;
}

};