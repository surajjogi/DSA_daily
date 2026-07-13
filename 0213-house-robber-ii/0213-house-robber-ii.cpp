class Solution {
public:
     int maxcost(vector<int>&dp,vector<int>&nums,int n){
        if(n==0){
            return nums[0];

        }
        if(n==1){
            return max(nums[0],nums[1]);
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=max(nums[n]+maxcost(dp,nums,n-2),maxcost(dp,nums,n-1));
     }

    
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
      vector<int> dp1(n - 1, -1);
vector<int> dp2(n - 1, -1);
        vector<int> withoutFirst(nums.begin() + 1, nums.end());
        int n1=withoutFirst.size();
        vector<int> withoutLast(nums.begin(), nums.end() - 1);
        int n2=withoutLast.size();
        int max1=maxcost(dp1,withoutFirst,n1-1);
        int max2=maxcost(dp2,withoutLast,n1-1);
        if(max1>max2){
            return max1;
        }
        return max2;
    }
};