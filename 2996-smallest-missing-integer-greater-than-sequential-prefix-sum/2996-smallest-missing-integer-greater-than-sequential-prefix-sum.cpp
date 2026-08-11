class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int maxSum = nums[0];
        int i = 1;
        int n = nums.size();
        while (i < n) {
            if (nums[i] == nums[i - 1] + 1) {
                maxSum += nums[i];
                i++;
            } else {
                break;
            }
        }
        set<int> s;
        for (int e : nums) {
            s.insert(e);
        }
        i=1;
        while(i){
            if(s.find(maxSum)!=s.end()){
                maxSum++;
            }
            else{
                i=0;
            }
        }
        return maxSum;
    }
};