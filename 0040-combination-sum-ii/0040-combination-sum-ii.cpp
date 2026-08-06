class Solution {
public:
 
    void combII(vector<int>& nums, int target, vector<vector<int>>& ans,
                vector<int>& comb, int i) {
        int n = nums.size();
        if (target == 0) {
                ans.push_back(comb);
            return;
        }
        if (i == n || target < 0) {
            return;
        }
        
        comb.push_back(nums[i]);
        combII(nums, target - nums[i], ans, comb, i + 1);
        comb.pop_back();
        int idx=i+1;
        while(idx<n&&nums[idx]==nums[idx-1]){
            idx++;
        }
        combII(nums, target, ans, comb,idx);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> comb;

        combII(candidates, target, ans, comb, 0);
        return ans;
    }
};