class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.size() <= 1)
			return 0;
		vector<int> dp(s.size(), 0);
		int max_length = 0;
		for (int i = 1; i < s.size(); ++i) {
			// 1. A valid string can't end with '('.
			if (s[i] == '(')
				dp[i] = 0;
			// 2. New ')' closes ajacent '('.
			else if (s[i - 1] == '(')
				dp[i] = (i - 2 >= 0? dp[i - 2] : 0) + 2;
			else {
				// 3. New ')' closes remote '('.
				int len = dp[i - 1];
				if (i - len - 1 >= 0 && s[i - len - 1] == '(') {
					dp[i] = dp[i - 1] + 2;
					// It may connect valid string before!
					if (i - len - 2 >= 0)
						dp[i] += dp[i - len - 2];
				}
			}
			max_length = max(max_length, dp[i]);
		}
		return max_length;
	}
};