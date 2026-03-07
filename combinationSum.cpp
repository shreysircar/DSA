#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
using namespace std;
/*
//brute
  void pick(int index, vector<int>& output, int sum, int target, vector<int>& candidates, set<vector<int>>& res) {
    if (sum == target) {
        res.insert(output);
        return;
    }
    if (sum > target || index >= candidates.size())
        return;

    // Include current
    output.push_back(candidates[index]);
    pick(index + 1, output, sum + candidates[index], target, candidates, res);
    output.pop_back();

    // Exclude current
    pick(index + 1, output, sum, target, candidates, res);
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end()); // sort to normalize order
    set<vector<int>> uniqueCombos;
    vector<int> output;
    pick(0, output, 0, target, candidates, uniqueCombos);

    // Convert set to vector
    return vector<vector<int>>(uniqueCombos.begin(), uniqueCombos.end());
}*/



void pick(int index,vector<int>&candidates,int targetSum,vector<int>output,vector<vector<int>>&res){
if(targetSum==0){
    res.push_back(output);              //basecase
    return;
} 

for(int i=index;i<candidates.size();i++){
if(i>index && candidates[i]==candidates[i-1]){
    continue;                                      //skip
}
if(candidates[i]>targetSum){break;}
output.push_back(candidates[i]);
pick(i+1,candidates,targetSum-candidates[i],output,res);
output.pop_back();
}
}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int index=0;
        vector<int>output;
        vector<vector<int>>res;
        int targetSum=target;
        pick(index,candidates,targetSum,output,res);
return res;
    }


int main(){
    vector<int>candidates={2,5,2,1,2};
    int target=5;
    vector<vector<int>> result = combinationSum2(candidates, target);

    cout << "Combinations that sum to " << target << ":\n";
    for (const auto& combo : result) {
        cout << "[ ";
        for (int num : combo) {
            cout << num << " ";
        }
        cout << "]\n";
    }

return 0;}

//combinationsum3: 
/*
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
using namespace std;

void pick(int index,int k,int sum,vector<int>output,vector<vector<int>>&res){
    if(output.size()==k && sum==0){
        res.push_back(output);            //basecase
        return;
    }
    if(sum<0 || output.size()>k){
        return;
    }

    for(int i=index;i<=9;i++){
    
        output.push_back(i);   
        if (i > sum) break;                                           //loop implicitly handles not pick
        pick(i+1,k,sum-i,output,res);   //include
output.pop_back();
    }
}

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>output;
       vector<vector<int>>res;
       int sum=n;
        pick(1,k,sum,output,res);
        return res;
    }
     
int main(){
vector<vector<int>>ans= combinationSum3(3,7);
    cout << "Subsets:\n";
    for (const auto& subset : ans) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

return 0;}

*/