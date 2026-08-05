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
    
      help(nums,i+1,powerSet,subset);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>subset;
        help(nums,0,ans,subset);
   set<vector<int>>st;
   for(int i=0;i<ans.size();i++){
    st.insert(ans[i]);
   }
    ans.clear();
    ans.assign(st.begin(),st.end());
    return ans;
    }
};