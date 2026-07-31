class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        for (char c : word)
            freq[c - 'a']++;

        vector<pair<int, char>> v;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0)
                v.push_back({freq[i], char(i + 'a')});
        }

        sort(v.begin(), v.end());
        int n = v.size() - 1;
        int step=0;
        for(int i=n;i>=0;i--){
             step+=((n-i)/8+1)*v[i].first;
        }
         return step;
    }
};