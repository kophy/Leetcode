class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[s.size() + 1][p.size() + 1];

        /*  case 1: both string are empty
        	obviously match
        */
        dp[0][0] = true;

        /* 	case 2: s is not empty while p is
        	always dismatch
        */
        for (int i = 1; i <= s.size(); ++i)
            dp[i][0] = false;

        /*  case 3: s is empty while p is not
        	match when p is like a*b*c*
        */
        for (int j = 1; j <= p.size(); ++j) {
            if (p[j - 1] == '*' && dp[0][j - 2])
                dp[0][j] = true;
            else
                dp[0][j] = false;
        }

        /*  case 4: both s and p are not empty */
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= p.size(); ++j) {
                // case 4.1: last characters are the same
                if (s[i - 1] == p[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                // case 4.2: last character of p is '.'
                else if (p[j - 1] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                // case 4.3: last character of p is '*'
                else if (p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                else
                    dp[i][j] = false;
            }
        }
        return dp[s.size()][p.size()];
    }
};