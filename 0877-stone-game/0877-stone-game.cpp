class Solution {
public:
 int maxDiff(vector<int>& nums, int left, int right,vector<vector<int>>& dp) {
        if (left == right) {
            return nums[left];
        }
        if(dp[left][right]!=-1)
        {
            return dp[left][right];
        }
        int scoreL = nums[left] - maxDiff(nums, left + 1, right,dp);
        int scoreR = nums[right] - maxDiff(nums, left, right - 1,dp); 
        return dp[left][right]= max(scoreL,scoreR);
        }
    bool stoneGame(vector<int>& piles) {
         int n = piles.size();
       vector<vector<int>> dp(n, vector<int>(n, -1));
        return maxDiff(piles, 0, n - 1,dp) >= 0;
    }
};