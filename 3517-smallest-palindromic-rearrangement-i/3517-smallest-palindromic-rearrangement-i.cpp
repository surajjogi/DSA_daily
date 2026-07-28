class Solution {
public:
    string smallestPalindrome(string s) {
        int size=s.size();
        int mid=0;
        if(size%2==0){
            mid=size/2;
        }
        else{
            mid=(size-1)/2;
        }
        sort(s.begin()+0,s.begin()+mid);
        int n=size-1;
        for(int i=0;i<mid;i++){
         s[n]=s[i];
         n=n-1;
         
        }
        return s;
    }
};