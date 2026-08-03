class Solution {
public:
     int stoneGame(vector<int>& stoneValue,int i,vector<int>&dp){
        int n=stoneValue.size();

        if(i>=n) return 0;
        if (dp[i] != -1){
    return dp[i];}
        int takeOne=stoneValue[i]-stoneGame(stoneValue,i+1,dp);
        int takeTwo=INT_MIN;
        if(i+1<n){
            takeTwo=(stoneValue[i]+stoneValue[i+1])-stoneGame(stoneValue,i+2,dp);
        }
        int takeThree=INT_MIN;
          if(i+2<n){
            takeThree=(stoneValue[i]+stoneValue[i+1]+stoneValue[i+2])-stoneGame(stoneValue,i+3,dp);
        }
     return dp[i]= max(takeOne,max(takeTwo,takeThree));
     }
    
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> dp(n + 1,-1);
        int value=stoneGame(stoneValue,0,dp);
        if(value>0){
            return "Alice";

        }

        else if(value<0){
            return "Bob";
        }
        else{
            return "Tie";
        }
    }
};