class Solution {
public:
	int minCost(vector<vector<int>>& costs) {
		int N = costs.size();
		if (N == 0)
			return 0;
		vector<vector<int>> dp(2, vector<int>(3, 0));
		dp[0] = costs[0];

		for (int i = 1; i < costs.size(); ++i) {
			dp[i % 2][0] = costs[i][0] + min(dp[(i - 1) % 2][1], dp[(i - 1) % 2][2]);
			dp[i % 2][1] = costs[i][1] + min(dp[(i - 1) % 2][0], dp[(i - 1) % 2][2]);
			dp[i % 2][2] = costs[i][2] + min(dp[(i - 1) % 2][0], dp[(i - 1) % 2][1]);
		}
		return min(dp[(N - 1) % 2][0], min(dp[(N - 1) % 2][1], dp[(N - 1) % 2][2]));
	}
};