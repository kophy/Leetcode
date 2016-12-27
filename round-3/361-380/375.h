class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> cost(n, vector<int>(n, -1));
        return getMoneyAmount(cost, 0, n - 1);
    }

private:
    int getMoneyAmount(vector<vector<int>> &cost, int start, int end) {
        if (start > end)
            return 0;
        if (cost[start][end] >= 0)
            return cost[start][end];
        if (start == end)
            cost[start][end] = 0;
        else {
            cost[start][end] = INT_MAX;
            for (int i = start; i <= end; ++i) {
                int temp = (i + 1) + max(getMoneyAmount(cost, start, i - 1), getMoneyAmount(cost, i + 1, end));
                cost[start][end] = min(cost[start][end], temp);
            }
        }
        return cost[start][end];
    }
};