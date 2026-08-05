class Solution {
public:
    void help(vector<int>& nums,int i,vector<vector<int>> &powerSet,vector<int>&subset){
    if(i==nums.size()){
        powerSet.push_back(subset);
        return ;
    }
    subset.push_back(nums[i]);
    help(nums,i+1,powerSet,subset);
    subset.pop_back();
    int idx=i+1;
    while(idx<nums.size()&&nums[idx]==nums[idx-1]){
        idx++;
    }
      help(nums,idx,powerSet,subset);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>subset;
        help(nums,0,ans,subset);
    return ans;
    }
};