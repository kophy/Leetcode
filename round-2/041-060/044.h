class Solution {
public:
    bool isMatch(string s, string p) {
        /*  equivalent as using a 2D vector,
        	but this 2D array version is faster.
        */
        bool **dp = new bool *[s.size() + 1];
        for (int i = 0; i <= s.size(); ++i) {
            dp[i] = new bool[p.size() + 1];
            /*  set default value to avoid useless operations
            	for example, when s is not empty but p is, the two string always don't match
            	another trick to accelerate
            */
            memset(dp[i], false, p.size() + 1);
        }

        /* two trivial cases */
        dp[0][0] = true;
        for (int j = 1; j <= p.size(); ++j)
            if (p[j - 1] == '*')
                dp[0][j] = dp[0][j - 1];

        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= p.size(); ++j) {
                if (s[i - 1] == p[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];	// core part: transition rule
            }
        }
        bool result = dp[s.size()][p.size()];
        for (int i = 0; i <= s.size(); ++i)
            delete[] dp[i];
        delete[] dp;
        return result;
    }
};