class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>left(nums.size());
        vector<int>right(nums.size());
        vector<int>ans(nums.size());
        left[0]=1;
       
        right[nums.size()-1]=1;
        for(int i=1;i<nums.size();i++){
        left[i]=left[i-1]*nums[i-1];
         
        }
        for(int i=nums.size()-2;i>=0;i--){
           right[i]=right[i+1]*nums[i+1];
        }
        for(int i=0;i<nums.size();i++){
            ans[i]=right[i]*left[i];
        }
       return ans;
    }


};




// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> output(n);
//         output[0] = 1;
//         for(int i=1; i<n; i++){
//             output[i] = output[i-1] * nums[i-1];
//         }
//         int right = 1;
//         for(int i=n-1; i>=0; i--){
//             output[i] *= right;
//             right *= nums[i];
//         }
//         return output;
//     }
// };