class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0, open = 0;
        vector<int> dp(s.size(), 0);
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(')
				++open;
            else if(open > 0) {
                dp[i] = 2 + dp[i - 1];
                dp[i] += (i - dp[i] > 0) ? dp[i - dp[i]] : 0;
                result = max(result, dp[i]);
                --open;
            }
        }
        return result;
    }
};