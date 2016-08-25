class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        int min_price = prices[0];
        int max_profit = INT_MIN;
        for (int i = 1; i < prices.size(); ++i) {
            int curr_profit = prices[i] - min_price;
            max_profit = max(max_profit, curr_profit);
            min_price = min(min_price, prices[i]);
        }
        return max(max_profit, 0);
    }
};