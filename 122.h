class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int day = 0;
        while (day < prices.size()) {
            int i = day;
            while (i + 1 < prices.size() && prices[i + 1] <= prices[i])
                ++i;
            int j = i;
            while (j + 1 < prices.size() && prices[j + 1] >= prices[j])
                ++j;
            if (j < prices.size())
                profit += prices[j] - prices[i];
            day = j + 1;
        }
        return profit;
    }
};