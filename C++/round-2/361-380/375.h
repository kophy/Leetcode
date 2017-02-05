class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> cost(n + 1, vector<int>(n + 1, 0));
        return calculateCost(cost, 1, n);
    }

private:
    int calculateCost(vector<vector<int>> &cost, int s, int e) {
        /*  case 1: from analysis
            When s == e, there is only one element in the range; so success is guaranteed (cost is 0).
        */
        if (s >= e)
            return 0;

        /* case 2: stored answers */
        if (cost[s][e] > 0)
            return cost[s][e];

        /* case 3: Minimize Maximum Cost */
        cost[s][e] = INT_MAX;
        for (int i = s; i <= e; ++i) {
            // current maximum expected cost
            int temp = i + max(calculateCost(cost, s, i - 1), calculateCost(cost, i + 1, e));
            // minimize maximum expected cost
            cost[s][e] = min(cost[s][e], temp);
        }
        return cost[s][e];
    }
};