#include<iostream>
#include<string>
#include<vector>
using namespace std;

void generateParentheses(int open, int close, string current, vector<string>& result, int n) {
    // Base case: if the current string is of length 2*n, it's valid
    if (current.length() == 2 * n) {
        result.push_back(current);
        return;
    }

    // Add '(' if we still have remaining open brackets
    if (open < n) {
        generateParentheses(open + 1, close, current + "(", result, n);
    }

    // Add ')' only if it doesn't exceed number of open brackets
    if (close < open) {
        generateParentheses(open, close + 1, current + ")", result, n);
    }
}

    vector<string> generateParenthesis(int n) {
vector<string>result;
       generateParentheses(0,0,"",result,n);
       return result; 
    }

int main(){
    vector<string> res=generateParenthesis(3);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<"   " ; 
    }
    return 0;
}