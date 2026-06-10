class Solution {
public:
using T = pair<int,pair<int,int>>;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
       pair<int,int>p;
       int n=nums1.size();
       int m=nums2.size();
       set<pair<int,int>>visited;
       priority_queue<T,vector<T>,greater<T>>minHeap;  //(sum,{i,j})
        minHeap.push({nums1[0]+nums2[0],make_pair(0,0)});
        visited.insert({0,0});
                vector<vector<int>>res;
                int cnt=k;
        while(cnt!=0 && !minHeap.empty()){
            res.push_back({nums1[minHeap.top().second.first],nums2[minHeap.top().second.second]});
            int i=minHeap.top().second.first;
            int j=minHeap.top().second.second;
            minHeap.pop();

        if(i!=n-1 && visited.find({i+1, j}) == visited.end()){
                minHeap.push({nums1[i+1]+nums2[j],make_pair(i+1,j)});
                          visited.insert({i+1,j});
                }
             if(j!=m-1 && visited.find({i,j+1}) == visited.end()){
                minHeap.push({nums1[i]+nums2[j+1],make_pair(i,j+1)});
                          visited.insert({i,j+1});}
            cnt--;
        }
        return res;
    }
};