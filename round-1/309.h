class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN, sell = 0;
        int prev_sell = 0, prev_buy;
        for (int i = 0; i < prices.size(); ++i) {
            prev_buy = buy;
            buy = max(buy, prev_sell - prices[i]);
            prev_sell = sell;
            sell = max(sell, prev_buy + prices[i]);
        }
        return sell;
    }
};