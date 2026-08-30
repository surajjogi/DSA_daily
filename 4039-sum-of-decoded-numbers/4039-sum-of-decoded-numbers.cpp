class Solution {
public:
    long long MOD = 1000000007;

    long long power(long long x, long long y) {
        long long ans = 1;

        while(y > 0) {
            if(y % 2 == 1) {
                ans = (ans * x) % MOD;
            }

            x = (x * x) % MOD;
            y /= 2;
        }

        return ans;
    }

    int sumDecoded(vector<long long>& nums) {
        long long total = 0;

        for(long long num : nums) {

            // 1. Get width
            int width = num % 10;

            // 2. Remove width digit
            long long d = num / 10;

            // 3. Convert d into string
            string s = to_string(d);

            // 4. Separate x and y
            string sx = s.substr(0, width);
            string sy = s.substr(width);

            long long x = stoll(sx);
            long long y = stoll(sy);

            // 5. Calculate x^y
            long long value = power(x, y);

            // 6. Add
            total = (total + value) % MOD;
        }

        return total;
    }
};