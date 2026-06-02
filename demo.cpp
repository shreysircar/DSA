#include <bits/stdc++.h>
using namespace std;


int main(){
vector<int>nums={1,4,5,2,0,9,10};
for(int i=0;i<nums.size();i++){
    cout<<nums[i]<<" ";
}
cout<<endl;
sort(nums.begin(),nums.end());
for(int i=0;i<nums.size();i++){
    cout<<nums[i]<<" ";
}
cout<<endl;
sort(nums.begin(),nums.end(),greater<int>());
for(int i=0;i<nums.size();i++){
    cout<<nums[i]<<" ";
}
return 0;}
