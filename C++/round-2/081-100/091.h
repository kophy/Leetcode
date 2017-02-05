class Solution {
public:
    /*  the problem with backtracking is the same sub-problem will be calculated many times,
    	if answers are not stored
    	here we use DP method because we only care total number of solutions, not what they contain
    */
    int numDecodings(string s) {
        if (s.size() == 0)
            return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        dp[1] = (s[0] >= '1' && s[0] <= '9')? 1 : 0;

        for (int i = 1; i < s.size(); ++i) {
            /*  I am still considering if it is true…
            	information in both DP and backtracking goes from bottom to top
            	it seems like DP is faster, but unable to handle cases when constraints or objectives are complicated
            	backtracking is slower, but can handle complex cases
            */
            int one = s[i] - '0';
            int two = (s[i - 1] - '0') * 10 + (s[i] - '0');

            if (one >= 1 && one <= 9)
                dp[i + 1] += dp[i];
            if (two >= 10 && two <= 26)
                dp[i + 1] += dp[i - 1];
        }

        return dp[s.size()];
    }
};