class Solution {
public:
    bool isPalindromic(string s) {
        vector<int>v;
        int i=0;
        while(i<s.size()){
            v.push_back((s[i]-'a')+97);
            i++;
        }
        string ss="";
       i=0;
       while(i<v.size()){
        ss+=bitset<8>(v[i]).to_string();
        i++;
       }
       i=0;
       int left=0;
       int right=ss.size()-1;
     int num=ss.size()%2?ss.size()-1:ss.size();
      while(left<=num/2){
        if(ss[left]!=ss[right]){
            return 0;
        }
        left++;
        right--;
      }
     return 1;
    }
};