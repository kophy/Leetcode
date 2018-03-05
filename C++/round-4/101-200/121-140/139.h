class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int max_length = 0;
        for (string &word : wordDict)
            max_length = max(max_length, (int)word.size());
        
        int N = s.size();
        vector<bool> dp(N + 1, false);
        dp[0] = true;
        
        for (int i = 0; i < N; ++i) {
            if (!dp[i])
                continue;
            for (int len = 1; i + len <= N && len <= max_length; ++len) {
                string word = s.substr(i, len);
                if (wordSet.count(word))
                    dp[i + len] = true;
            }
        }
        return dp[N];
    }
};