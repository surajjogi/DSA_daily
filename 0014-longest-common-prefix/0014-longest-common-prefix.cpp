class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        sort(strs.begin(),strs.end());
        int n=strs.size();
        string st=strs[0];
        string en=strs[n-1];
        for(int i=0;i<min(st.size(),en.size());i++){
            if(st[i]!=en[i]){
                return ans;
            }
            ans+=st[i];
        }
        return ans;
    }
};