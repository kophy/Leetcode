class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size(), 0);	// the length of valid string contains s[i]
        int unclosed = 0, max_len = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                ++unclosed;
            if (s[i] == ')' && unclosed > 0) {
                dp[i] = dp[i - 1] + 2;
                if (i - dp[i] > 0)
                    dp[i] += dp[i - dp[i]];
                max_len = max(max_len, dp[i]);
                --unclosed;
            }
        }

        return max_len;
    }
};