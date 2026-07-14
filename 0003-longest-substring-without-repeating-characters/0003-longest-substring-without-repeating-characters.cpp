class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    
        int maxlen=0;
        unordered_set<char>st;
        int left=0,right=0;
       while(right<s.size()){
            while(st.find(s[right])!=st.end()){
                st.erase(s[left]);
                left++;

            }
            st.insert(s[right]);
            
             maxlen=max(maxlen,right-left+1);
            right++;
           
        }
        return maxlen;
    }
};