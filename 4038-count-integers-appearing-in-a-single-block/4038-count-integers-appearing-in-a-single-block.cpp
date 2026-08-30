class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int count = 0;
       
        map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        for (auto& [key, vec] : mp) {
 bool val = false;
            for (int i = 0; i < vec.size()-1; i++) {
             
                if (vec[i + 1] - vec[i] == 1) {
                    continue;
                } else {
                    val = true;
                    break;
                }
            }
            if (val == false) {
                count++;
            }
        }
        return count;
    }
};