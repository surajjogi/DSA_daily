class Solution {
public:
    int jump(vector<int>& nums) {
        int totaljump=0;
        int destination =nums.size()-1;
        int coverage=0,lastjumpidx=0;
        if(nums.size()==1){
            return 0;
        }
        for(int i=0;i<nums.size();i++){
            coverage=max(coverage,nums[i]+i);
            if(i==lastjumpidx){
                lastjumpidx=coverage;
                totaljump++;
            }
            if(lastjumpidx>=destination){
                return totaljump;
            }
        }
         return totaljump;
    }
};