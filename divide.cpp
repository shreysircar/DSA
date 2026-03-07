#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
    int divide(int dividend, int divisor) {
        if(dividend==divisor){
            return 1;
        }
        bool sign=true;
     if(dividend>=0 && divisor<0){sign=false;}
     if(dividend<0 && divisor>=0){sign=false;}
    int n=abs(dividend);  int d=abs(divisor);   int ans=0;
    while(n>=d){
        int cnt=0;
        while(n>=(d<<cnt+1)){
            cnt++; ans+=(1<<cnt);
            n=n-(d<<cnt);
        }
    }
    if(ans>=(1<<31) && sign==true){return INT_MAX;}
    if(ans<=((-1<<31)+1) && sign==false){return INT_MIN;}
    return sign?ans:((-1)*ans);
    }

int main(){

cout<<divide(22,3);

return 0;}
