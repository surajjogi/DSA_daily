class Solution {
public:
    void permutation(vector<int>& nums, vector<vector<int>>& ans,
                     vector<int>& temp, int i) {
        int n = nums.size();
        if (i == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int num : nums) {

            bool found = false;

            for (int x : temp) {
                if (x == num) {
                    found = true;
                    break;
                }
            }

            if (found)
                continue;
            temp.push_back(num);
            permutation(nums, ans, temp, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        permutation(nums, ans, temp, 0);
        return ans;
    }
};