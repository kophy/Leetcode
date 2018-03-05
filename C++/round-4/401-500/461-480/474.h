class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

		// classic pattern when each item can be used only once, here just in 2D space
		for (string &str : strs) {
			vector<int> count(2, 0);
			for (char c : str)
				++count[c - '0'];

			for (int i = m; i >= count[0]; --i) {
				for (int j = n; j >= count[1]; --j) {
					dp[i][j] = max(dp[i][j], dp[i - count[0]][j - count[1]] + 1);
				}
			}
		}
		return dp[m][n];
	}
};