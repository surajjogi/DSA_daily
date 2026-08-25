class Solution {
public:
    bool isPalindromic(string s) {
        vector<int> v;

        for (int i = 0; i < s.size(); i++) {
            v.push_back((s[i] - 'a') + 97);
        }

        string ss = "";

        for (int i = 0; i < v.size(); i++) {
            ss += bitset<8>(v[i]).to_string();
        }

        int left = 0;
        int right = ss.size() - 1;

        while (left < right) {
            if (ss[left] != ss[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};