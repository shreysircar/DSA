#include <bits/stdc++.h>
using namespace std;


    bool isPalindrome(string s) {
        int n=s.length();
        string res;
        for(int i=0;i<n;i++){
            if(s[i]>='a' && s[i]<='z'){ //small alphabet
                res.push_back(s[i]);
            }
            else if(s[i]>='A' && s[i]<='Z'){//capital alphabet ->convert to small
             res.push_back('a'+(s[i]-'A'));
            }
            else if(s[i]>='0' && s[i]<='9'){
                res.push_back(s[i]);
            }
            else{
                continue;
            }
        }
         n=res.length();
        string res2=res;
        reverse(res2.begin(),res2.end());
                for(int i=0;i<n;i++){
         cout<<res[i];
        }
        cout<<endl;
                for(int i=0;i<n;i++){
           cout<<res2[i];
        }
        bool check=true;
        for(int i=0;i<n;i++){
            if(res[i]!=res2[i]){check=false;}
        }
return check;
    }


int main(){
      string ans="A man, a plan, a canal: Panama";
      bool check=isPalindrome(ans);
      cout<<check;
return 0;}