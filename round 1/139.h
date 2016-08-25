class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j <= i; ++j) {
                string temp = s.substr(j, i - j + 1);
                if (dp[j] && wordDict.find(temp) != wordDict.end()) {
                    dp[i + 1] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};