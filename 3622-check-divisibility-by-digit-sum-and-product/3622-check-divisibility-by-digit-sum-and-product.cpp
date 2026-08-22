class Solution {
public:
    bool checkDivisibility(int n) {
        int num=n;
        long long sum=0;
        long long product=1;
        while(num>0){
            sum+=num%10;
            product*=1LL*num%10;
            num=num/10;

        }
        if((n%(sum+product))==0){
         return true;
        }
        return false;
    }
};