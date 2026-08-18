class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<=n-k;i++){
          for(int j=i;j<i+k;j++){
            mp[nums[j]]++;
          }

        }
        int ans=-1;
        for(auto it:mp){
            if(it.second==1){
                ans=max(ans,it.first);
            }
        }
        if(k==nums.size()){
            sort(nums.begin(),nums.end());
            return nums[nums.size()-1];
        }

        return ans;
    }
};