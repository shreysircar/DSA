#include<bits/stdc++.h>>
using namespace std;

class Solution {
public:
typedef pair<int,pair<int,int>>p;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
    priority_queue<p,vector<p>,greater<p>> pq;    //(distance,{i,j}); 
    vector<vector<int>>ans(n,vector<int>(m,INT_MAX));   
    int dr[4]={0,0,-1,1};
    int dc[4]={1,-1,0,0};

    ans[0][0] = 0;
    pq.push({0,{0,0}});
    while(!pq.empty()){
int dis = pq.top().first;
int x = pq.top().second.first;
int y = pq.top().second.second;
        pq.pop();
        for(int k=0;k<4;k++){
            int nr=x+dr[k];
            int nc=y+dc[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m){
              int newEffort=max(dis,abs(heights[x][y]-heights[nr][nc]));
                if(ans[nr][nc]>newEffort){
                    ans[nr][nc]=newEffort;
                    pq.push({newEffort,{nr,nc}});
                }
            }
        }
    }
    return ans[n-1][m-1];
    }
};