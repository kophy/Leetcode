class Solution {
public:
	/* allow only one transaction */
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        int profit = 0;
        int min_price = prices[0];
        int i = 0;
        while (i < prices.size()) {
            while (i + 1 < prices.size() && prices[i] >= prices[i + 1])
                ++i;
            min_price = min(min_price, prices[i]);
            while (i + 1 < prices.size() && prices[i] <= prices[i + 1])
                ++i;
            profit = max(profit, prices[i] - min_price);
            ++i;
        }

        return profit;
    }
};