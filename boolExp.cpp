class Solution {
public:
char solveOperator(vector<char> &ans,char op){
    if(op=='!'){
        return ans[0]=='t'? 'f': 't';
    }
    if(op=='&'){
        for(char &ch: ans){
            if(ch=='f'){return 'f';}
        }
        return 't';
    }

        if(op=='|'){
        for(char &ch: ans){
            if(ch=='t'){return 't';}
        }
        return 'f';
    }
    return 't';
}
    bool parseBoolExpr(string expression) {
        int n=expression.length();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(expression[i]==','){continue;}
            if(expression[i]!=')'){
            st.push(expression[i]);}
            else{
                vector<char>ans;
                while(st.top()!='('){
                    ans.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op=st.top();
                st.pop();
                st.push(solveOperator(ans,op));
            }
        }
return st.top()=='t' ? true : false;
    }
};