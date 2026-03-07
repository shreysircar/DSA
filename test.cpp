#include <bits/stdc++.h>
#include <iostream>
using namespace std;
    int minOperations(string s) {
    int flipsodd=0;
    int flipseven=0;
    int n=s.length();

    if(s[0]=='0'){
        for(int i=0;i<n;i++){
            if(i%2==0 && s[i]!='0'){
           flipseven++;
            }
            else if(i%2==1 && s[i]!='1'){
                flipsodd++;}
        }

    }
    else{
        for(int i=0;i<n;i++){
            if(i%2==0 && s[i]!='1'){
           flipseven++;
            }
            else if(i%2==1 && s[i]!='0'){
                flipsodd++;}
        }
    }
return flipseven+flipsodd;
    }
int main() {
string s="0101";
cout<<minOperations(s);
return 0;
}
