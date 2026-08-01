class Solution {
public:
    int maxDiff(vector<int>& nums, int left, int right, int n,
                vector<vector<int>>& dp) {
        if (left == right) {
            return nums[left];
        }

        if (dp[left][right] != -1) {
            return dp[left][right];
        }

        int scoreL = nums[left] - maxDiff(nums, left + 1, right, n, dp);
        int scoreR = nums[right] - maxDiff(nums, left, right - 1, n, dp);

        dp[left][right] = max(scoreL, scoreR);
        return dp[left][right];
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return maxDiff(nums, 0, n - 1, n, dp) >= 0;
    }
};