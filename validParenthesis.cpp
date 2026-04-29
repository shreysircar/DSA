#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    bool checkValidString(string s) {
        int n=s.length();
   int mini=0;
   int maxi=0;
   for(int i=0;i<n;i++){

    if(s[i]=='('){
        maxi++;
        mini++;
    }
    else if(s[i]==')'){
        if(mini>0){
            mini--;
        }
        maxi--;
    }
    else{   // '*'
    if(mini>0){
        mini--;
    }
    maxi++;
    }
        if(maxi<0){return false;}
   }
   if(mini==0){return true;}
   return false;
    }
};