class Solution {
public:
    set<vector<int>> s;

    void combSum(vector<int>& nums, int target, vector<int>& comb,vector<vector<int>>& ans, int i, int n) {
        if (i == n || target < 0) {
            return;
        }
        if (target == 0) {
            if (s.find(comb) == s.end()) {
                ans.push_back(comb);
                s.insert(comb);
            }
            return;
        }
        comb.push_back(nums[i]);
        combSum(nums, target - nums[i], comb, ans, i + 1, n);
        combSum(nums, target - nums[i], comb, ans, i, n);
        comb.pop_back();
        combSum(nums, target, comb, ans, i + 1, n);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        vector<vector<int>> ans;
        int n = candidates.size();
        combSum(candidates, target, comb, ans, 0, n);
        return ans;
    }
};