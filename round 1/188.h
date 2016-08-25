class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k >= prices.size() - 1) {
            int result = 0;
            for (int i = 1; i < prices.size(); ++i)
                result += max(0, prices[i] - prices[i - 1]);
            return result;
        }
        vector<int> buy(k + 1, INT_MIN), sell(k + 1, 0);
        for (int i = 0; i < prices.size(); ++i) {
            for (int j = 1; j <= k; ++j) {
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k];
    }
};