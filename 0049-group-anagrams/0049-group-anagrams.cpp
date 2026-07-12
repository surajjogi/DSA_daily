class Solution {
public:
// trick
//mp["asd"].push_back("one");
// mp["asd"].push_back("two");

// Now the map contains:

// "asd" -> {"one", "two"}
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++){
            string ss=strs[i];
            sort(ss.begin(),ss.end());
            mp[ss].push_back(strs[i]);
        }
        vector<vector<string>>v;
        for(auto it:mp){
            v.push_back(it.second);
        }

return v;

    }
};