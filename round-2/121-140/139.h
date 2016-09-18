class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        /*  dp[i] indicates whether s.substr(0, i) can be broken */
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        /*  there is no constraint about how many times a word can be used,
        	so we don't have to use BFS/DFS
        */
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j >= 0; --j) {
                string word = s.substr(j, i - j + 1);
                if (dp[j] && wordDict.find(word) != wordDict.end()) {
                    dp[i + 1] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};