//recursion
class Solution {
public:
typedef long long ll;
    static const int MOD = 1e9+7;
int N,M;

int solve(int i,int prevVal,bool flag){
if(i>=N){return 1;} //reached till end of zigzag arr & completed 1 zigzag arr
    ll res=0;
    if(flag){
        for(int nextVal=prevVal+1;nextVal<=M;nextVal++){
            res+=solve(i+1,nextVal,false)%MOD;;
        }
    }
    else{
              for(int nextVal=1;nextVal<prevVal;nextVal++){
            res+=solve(i+1,nextVal,true)%MOD;
        }  
    }
return res;
}

    int zigZagArrays(int n, int l, int r) {
        N=n;
        M = r - l + 1;
        l=1;
        r=M;
ll res=0;
for(int startVal=l;startVal<=M;startVal++){
    //i=0->startVal
    //next inc
    res+=solve(1,startVal,true) % MOD;
    //next dec
        res+=solve(1,startVal,false) % MOD;
}
    
        return (int)res;
    }
};

//memoization
class Solution {
public:
typedef long long ll;
    static const int MOD = 1e9+7;
int N,M;
int t[2001][2001][2];
int solve(int i,int prevVal,bool flag){
if(i>=N){return 1;} //reached till end of zigzag arr & completed 1 zigzag arr
if(t[i][prevVal][flag]!=-1){
    return t[i][prevVal][flag];
}
    ll res=0;
    if(flag){
        for(int nextVal=prevVal+1;nextVal<=M;nextVal++){
            res=(res+solve(i+1,nextVal,false))%MOD;
        }
    }
    else{
              for(int nextVal=1;nextVal<prevVal;nextVal++){
            res=(res+solve(i+1,nextVal,true))%MOD;
        }  
    }
return t[i][prevVal][flag]=res;
}

    int zigZagArrays(int n, int l, int r) {
        N=n;
        M = r - l + 1;
        l=1;
        if(N==1){return M;}
        r=M;
         memset(t,-1,sizeof(t));
ll res=0;
for(int startVal=l;startVal<=M;startVal++){
    //i=0->startVal
    //next inc
    res=(res+solve(1,startVal,true)) % MOD;
    //next dec
        res=(res+solve(1,startVal,false)) % MOD;
}
    
        return (int)res;
    }
};

//bottom up
//T.C : O(n*m*m), we have n*m*2 states and we run for loop inside the recursion
//S.C : O(n*m)
class Solution {
public:
    int MOD = 1e9+7;
    typedef long long ll;

    int zigZagArrays(int n, int l, int r) {
        int N = n;
        int M = r-l+1;

        ll t[2001][2001][2];
        memset(t, 0, sizeof(t));

        //Base Case
        for(int prevVal = 1; prevVal <= M; prevVal++) {
            t[N][prevVal][0] = 1;
            t[N][prevVal][1] = 1;
        }

        for(int i = N-1; i >= 0; i--) {

            for(int prevVal = 1; prevVal <= M; prevVal++) {

                for(int nextVal = prevVal+1; nextVal <= M; nextVal++) {
                    t[i][prevVal][1] = (t[i][prevVal][1] + t[i+1][nextVal][0]) % MOD;
                }

                for(int nextVal = 1; nextVal < prevVal; nextVal++) {
                    t[i][prevVal][0] = (t[i][prevVal][0] + t[i+1][nextVal][1]) % MOD;
                }

            }
        }

        ll result = 0;

        for(int startVal = 1; startVal <= M; startVal++) {
            //a < b > c < d ...
            result = (result + t[1][startVal][1]) % MOD;

            //a > b < c > d...
            result = (result + t[1][startVal][0]) % MOD;
        }

        return result;
        
    }
};


//optimal

//Approach-3 (Bottom Up + Prefix Sum) - TLE
//T.C : O(n*m)
//S.C : O(n*m)
class Solution {
public:
    int MOD = 1e9+7;
    typedef long long ll;

    int zigZagArrays(int n, int l, int r) {
        int N = n;
        int M = r-l+1;

        ll t[2001][2001][2];

        //Base Case
        for(int prevVal = 1; prevVal <= M; prevVal++) {
            t[N][prevVal][0] = 1;
            t[N][prevVal][1] = 1;
        }

        for(int i = N-1; i >= 0; i--) {

            vector<ll> prefDir0(M+1, 0);
            vector<ll> prefDir1(M+1, 0);

            for(int prevVal = 1; prevVal <= M; prevVal++) {
                
                prefDir0[prevVal] = (prefDir0[prevVal-1] + t[i+1][prevVal][0]) % MOD;

                prefDir1[prevVal] = (prefDir1[prevVal-1] + t[i+1][prevVal][1]) % MOD;

            }

            for(int prevVal = 1; prevVal <= M; prevVal++) {
                
                t[i][prevVal][1] = (prefDir0[M] - prefDir0[prevVal] + MOD) % MOD;

                t[i][prevVal][0] = prefDir1[prevVal-1];

            }
        }

        ll result = 0;

        for(int startVal = 1; startVal <= M; startVal++) {
            //a < b > c < d ...
            result = (result + t[1][startVal][1]) % MOD;

            //a > b < c > d...
            result = (result + t[1][startVal][0]) % MOD;
        }

        return result;
        
    }
};