class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int dp[m + 1][n + 1];

        /*  case 1: both strings are empty
        	obviously distance equals 0
        */
        dp[0][0] = 0;

        /*  case 2: one string is empty and the other is not
        	delete characters in the non-empty string
        */
        for (int i = 1; i <= m; ++i)
            dp[i][0] = i;
        for (int j = 1; j <= n; ++j)
            dp[0][j] = j;

        /*  case 3: both strings are not empty
        	dp[i][j] is the distance between word1[0:i] and word2[0:j]
        	dp[i - 1][j] -> dp[i][j] or	dp[i][j - 1] -> dp[i][j] needs an insert operation
        	judge whether dp[i - 1][j - 1] -> dp[i][j] needs a replace operation
        */
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = (word1[i - 1] == word2[j - 1])? dp[i - 1][j - 1] : dp[i - 1][j - 1] + 1;
                dp[i][j] = min(dp[i][j], min(dp[i - 1][j], dp[i][j - 1]) + 1);
            }
        }
        return dp[m][n];
    }
};