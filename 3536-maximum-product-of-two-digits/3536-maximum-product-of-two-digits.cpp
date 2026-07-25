class Solution {
public:
    int maxProduct(int n) {
       vector<int>temp;
       while(n){
        temp.push_back(n%10);
        n=n/10;
       }
       sort(temp.begin(),temp.end());
       int size=temp.size();
       int ans=temp[size-1]*temp[size-2];
       return ans;
    }
};