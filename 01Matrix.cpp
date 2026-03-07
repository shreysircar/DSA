#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

   vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> res(m, vector<int>(n, -1));

        queue<pair<int,int>> q;

        int dr[4] = {0,0,-1,1};
        int dc[4] = {-1,1,0,0};

        // STEP 1: push all 0s into queue
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    res[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        // STEP 2: BFS
        while(!q.empty()){

            auto p = q.front();
            q.pop();

            for(int k=0;k<4;k++){

                int nr = p.first + dr[k];
                int nc = p.second + dc[k];

                if(nr>=0 && nr<m && nc>=0 && nc<n && res[nr][nc]==-1){

                    res[nr][nc] = res[p.first][p.second] + 1;
                    q.push({nr,nc});
                }
            }
        }

        return res;
    }
};