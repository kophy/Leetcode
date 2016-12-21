class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (string str : strs) {
            int dm = countZeros(str);
            int dn = str.size() - dm;
            // reverse order to avoid reusing
            for (int i = m; i - dm >= 0; --i) {
                for (int j = n; j - dn >= 0; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - dm][j - dn] + 1);
                }
            }
        }
        return dp[m][n];
    }

private:
    int countZeros(string str) {
        int count = 0;
for (char c : str)
            if (c == '0')
                ++count;
        return count;
    }
};