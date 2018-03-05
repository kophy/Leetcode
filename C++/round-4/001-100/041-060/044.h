class Solution {
public:
	bool isMatch(string s, string p) {
		int M = s.size(), N = p.size();
		vector<vector<bool>> dp(M + 1, vector<bool>(N + 1, false));
		dp[0][0] = true;
		for (int j = 0; j < N; ++j)
			dp[0][j + 1] = dp[0][j] && (p[j] == '*');

		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < N; ++j) {
				if (p[j] == '?')
					dp[i + 1][j + 1] = dp[i][j];
				else if (p[j] == '*')
					dp[i + 1][j + 1] = dp[i][j] || dp[i][j + 1] || dp[i + 1][j];
				else
					dp[i + 1][j + 1] = dp[i][j] && s[i] == p[j];
			}
		}

		return dp[M][N];
	}
};