#include <bits/stdc++.h>
#include <iostream>
using namespace std;
    long long left(int i,vector<int>&nums){
                int n=nums.size();
        long long sum=0;
        if(i==0){
            return 0;
        }
        for(int j=0;j<i;j++){
            sum+=nums[j];
        }
        return sum;
    }

    long long right(int i,vector<int>&nums){
                int n=nums.size();
                long long mul=1;
        if(i==n-1){
            return 1;
        }
        for(int j=i+1;j<n;j++){
             mul=(mul*nums[j]);
        }
        return mul;
    }

    bool isBalanced(long long left,long long right){
      if(left==right){
          return true;
      }  
        return false;
    }
    int smallestBalancedIndex(vector<int>& nums) {
        int n=nums.size();
int minIndex=INT_MAX;
        for(int i=0;i<n;i++){
        long long l=left(i,nums);
        long long r=right(i,nums);   
        if(isBalanced(l,r)){
          minIndex=min(minIndex,i);  
        }
        }
        if(minIndex>=0 && minIndex!=INT_MAX){
            return minIndex;
        }
        return -1;
    }
int main() {
vector<int>vec={2,1,2};
cout<<smallestBalancedIndex(vec);
return 0;
}
