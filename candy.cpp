class Solution {
public:
    int candy(vector<int>& ratings) {
        int children=ratings.size();
        int cnt=0;
        vector<int>L2R(children,1);
                vector<int>R2L(children,1);
          for(int i=1;i<children;i++){   //left pass
                if(ratings[i]>ratings[i-1]){
                  L2R[i]=L2R[i-1]+1;
                }
          }

          for(int i=children-2;i>=0;i--){
                if(ratings[i]>ratings[i+1]){
                  R2L[i]=R2L[i+1]+1;
                }
          }

for(int i=0;i<children;i++){
    L2R[i]=max(L2R[i],R2L[i]);
    cnt+=L2R[i];
}
return cnt;
    }
};


//approach2
