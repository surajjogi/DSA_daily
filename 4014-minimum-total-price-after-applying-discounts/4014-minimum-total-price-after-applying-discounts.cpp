class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end(), greater<int>());
        sort(discounts.begin(), discounts.end(), greater<int>());
        int common = min(prices.size(), discounts.size());
        double cal = 0;
        for (int i = 0; i < common; i++) {
            cal += (1LL * prices[i] * (100 - discounts[i])) / 100.0;
        }
        for (int i = common; i < prices.size(); i++) {
            cal += prices[i];
        }
    
        return cal;
    }
};