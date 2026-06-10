#include<iostream>
#include<string>
using namespace std;
//recursion
class Solution{
    public:
    string s;
    int n;
    typedef long long ll;
     
pair<ll,ll> solve(int curr,int prePrev,int prev, bool isLimitedWithActualNo, bool isLeadingZero){
if(curr==n){
    return {1,0}; //no more score can be generated since we found the last no
}
ll totalNos=0; //one peak may contribute to many numbers->how many numbers can be formed from this state
ll totalWaveScore=0;//total waviness of all those numbers
int limitDigit=isLimitedWithActualNo? (s[curr]-'0') : 9;

for(int digit=0;digit<=limitDigit;digit++){
    bool newIsLeadingZero=isLeadingZero && (digit==0);  
int newPrePrev=prev;
int newPrev=newIsLeadingZero ? -1 : digit;
auto [remTotalNos, remTotalWaveScore]=solve(curr+1,newPrePrev,newPrev,isLimitedWithActualNo && (digit==limitDigit), newIsLeadingZero);
if(!newIsLeadingZero && prePrev>=0 && prev>=0){
    bool isPeak =(prePrev<prev && prev>digit);
    bool isValley=(prePrev>prev && prev<digit);
    if(isPeak || isValley){totalWaveScore+=remTotalNos;}
}
}
totalNos+=remTotalNos
totalWaveScore+=remTotalWaveScore;
return {totalNos,totalWaveScore};
}

    ll func(int num){
        if(num<100){  //atleast 3 digits needed (0-99 not valid)
            return 0;
        }
        string s=to_string(num);
        int n=s.length();
      auto [totalNumbers, totalWaveScore]=solve(0,-1,-1,true,true);
  return totalWaveScore;
    }

    long long totalWaviness(long long num1, long long num2) {
        return func(num2) - func(num1 - 1);
    }
}; 
    
    
// solve(...)-> "Starting from position curr, given the last two chosen digits, how many valid numbers can I build and what is the total waviness of all of them?"


//memoization

class Solution {
public:
 typedef long long ll;
    string s;
    int n;

    ll dpTotalNumbers[16][10][10];
    ll dpTotalWaviness[16][10][10];

    pair<ll, ll> solve(int curr, int prevPrev, int prev, bool isLimitedWithActualNumber, bool isLeadingZero) {
        if (curr == n) {
            return {1, 0}; // no more score can be generated and we found one last number
        }

        if (!isLimitedWithActualNumber && !isLeadingZero && prevPrev >= 0 && prev >= 0) {
            if (dpTotalNumbers[curr][prevPrev][prev] != -1) {
                return {dpTotalNumbers[curr][prevPrev][prev], dpTotalWaviness[curr][prevPrev][prev]};
            }
        }

        ll totalNumbers   = 0;
        ll totalWaveScore = 0;

        int limitDigit = isLimitedWithActualNumber ? (s[curr] - '0') : 9;

        for (int digit = 0; digit <= limitDigit; digit++) {
            bool newIsLeadingZero = isLeadingZero && (digit == 0);

            int newPrevPrev = prev;
            int newPrev     = newIsLeadingZero ? -1 : digit;

            auto [remainTotalNumbers, remainTotalWaveScore] = solve(
                curr + 1, newPrevPrev, newPrev,
                isLimitedWithActualNumber && (digit == limitDigit),
                newIsLeadingZero
            );

            if (!newIsLeadingZero && prevPrev >= 0 && prev >= 0) {
                bool isPeak   = (prevPrev < prev && prev > digit);
                bool isValley = (prevPrev > prev && prev < digit);

                if (isPeak || isValley) {
                    totalWaveScore += remainTotalNumbers;
                }
            }

            totalNumbers   += remainTotalNumbers;
            totalWaveScore += remainTotalWaveScore;
        }

        if (!isLimitedWithActualNumber && !isLeadingZero && prevPrev >= 0 && prev >= 0) {
            dpTotalNumbers[curr][prevPrev][prev]  = totalNumbers;
            dpTotalWaviness[curr][prevPrev][prev] = totalWaveScore;
        }

        return {totalNumbers, totalWaveScore};
    }

    ll func(ll num) {
        if (num < 100) { // we need at least 3 digits (0 to 99 are invalid)
            return 0;
        }

        memset(dpTotalNumbers, -1, sizeof(dpTotalNumbers));
        memset(dpTotalWaviness, -1, sizeof(dpTotalWaviness));

        s = to_string(num);
        n = s.length();

        auto [totalNumbers, totalWaveScore] = solve(0, -1, -1, true, true);

        return totalWaveScore;
    }

    long long totalWaviness(long long num1, long long num2) {
        return func(num2) - func(num1 - 1);
    }
};