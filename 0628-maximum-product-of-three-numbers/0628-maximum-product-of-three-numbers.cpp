class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        vector<int>ans=nums;
        sort(ans.begin(),ans.end());
        int size=nums.size();
        int first=ans[size-1]*ans[size-2]*ans[size-3];
        int second=ans[0]*ans[1]*ans[size-1];
        return (first>second)?first:second;
    }
};