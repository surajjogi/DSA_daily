class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int>s;
        for(auto it:nums){
            s.insert(it);
        }
        int number=k;
        while(s.count(number)){
            number+=k;

        }
        return number;
    }
};