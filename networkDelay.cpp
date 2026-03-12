#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       unordered_map<int,vector<pair<int,int>>>adj; //{node,distance}
        for(auto &vec:times){
int u=vec[0];
int v=vec[1];
int w=vec[2];
adj[u].push_back({v,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;  //{distance,node}
        vector<int>dist(n+1,INT_MAX);
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            int distance=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto &v: adj[node]){
int nextNode = v.first;
int weight = v.second;
       if(dist[nextNode]>distance + weight){
               dist[nextNode] = distance + weight;
                   pq.push({dist[nextNode], nextNode});
                }
            }
          
        }

int minTime=INT_MIN;
        for(int i=1;i<=n;i++){
       minTime=max(minTime,dist[i]);
        }

        if(minTime==INT_MAX){return -1;}

return minTime;
    }
};