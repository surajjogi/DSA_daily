class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans(2,0);
        int size=numbers.size();
        int left=0;
        int right=size-1;
        while(right>left){
            if(target<numbers[left]+numbers[right]){
                right--;
            }
            else if(target>numbers[left]+numbers[right]){
                left++;
            }
            else{
                ans[0]=left+1;
                ans[1]=right+1;
                break;
            }
        }
        return ans;


    }
};