class Solution {
public:
	int numDecodings(string s) {
		if (s.empty())
			return s.size();

		vector<int> dp(s.size() + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] != '0')
				dp[i + 1] = dp[i];
			if (i - 1 >= 0 && s[i - 1] != '0') {
				int idx = stoi(s.substr(i - 1, 2));
				if (idx >= 10 && idx <= 26)
					dp[i + 1] += dp[i - 1];
			}
		}
		return dp[s.size()];
	}
};