class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
      int five=0,ten=0,twenty=0;
      int n=bills.size();
      for(int i=0;i<n;i++){

        if(bills[i]==5){
            five++;
        }

        else if(bills[i]>5){
            if(bills[i]==20){   //if $20 is payed
            twenty++;
              if(ten>0 && five>0){
                ten--;
                five--;
              } 
              else if(five>=3){
                five=five-3;
              }
              else{return false;}
            }
            else if(bills[i]==10){   //if $10 is payed
            ten++;
                if(five>0){
                    five--;
                }
                else{
                    return false;
                }
            }

        }

      } 
     return true; 
    }
};