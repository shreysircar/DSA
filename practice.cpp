#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<unordered_map>
using namespace std;

   class queue{
public:
stack<int>s;
stack<int>s2;
void push(int n){
    s.push(n);
}

int front(){
if(!s2.empty()){
return s2.top();
}
else{
    int a=s.size();
    while(!s.empty()){
        s2.push(s.top());
        s.pop();
    }
    return s2.top();
}

}

void dequeue(){
    
}

   };


int main(){

return 0;}
