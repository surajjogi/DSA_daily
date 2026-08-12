class Solution {
public:
    void solve(int idx, map<int, string>& mp, vector<string>& ans, string& temp,
               string digits) {
        if (idx >= digits.size()) {
            ans.push_back(temp);
            return;
        }
        string s = mp[digits[idx]-'0'];
        for (int i = 0; i < s.size(); i++) {
            temp.push_back(s[i]);
            solve(idx + 1, mp, ans, temp, digits);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        map<int, string> mp = {{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"},
                               {6, "mno"},
                               {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};

        int idx = 0;
        string temp = "";
        vector<string> ans;
        solve(idx, mp, ans, temp, digits);
        return ans;
    }
};
    