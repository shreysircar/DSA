#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
using namespace std;

void pick(int index,vector<int>output,vector<vector<int>>&res,vector<int>&nums){

        res.push_back(output); // Add current subset

for(int i=index;i<nums.size();i++){
    if(i>index && nums[i]==nums[i-1]){
        continue;                           //skip
    }
    output.push_back(nums[i]);
    pick(i+1,output,res,nums);
    output.pop_back();

}
}

     vector<vector<int>>  subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
vector<int>output;
vector<vector<int>>res;
int index=0;
pick(index,output,res,nums);
return res;
    }
int main(){
vector<int> arr={1,2,2};
vector<vector<int>>ans= subsetsWithDup(arr);
    cout << "Subsets:\n";
    for (const auto& subset : ans) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

return 0;}

