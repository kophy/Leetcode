// solution 1: dp
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), [](string &a, string &b)->bool {
            return a.size() < b.size();
        });
        vector<bool> dp(words.size(), false);
        for (int i = 0; i < words.size(); ++i) {
            if (words[i].size() == 1) {
                dp[i] = true;
                continue;
            } else {
                int len = words[i].size();
                for (int j = i - 1; j >= 0 && words[j].size() >= len - 1; --j) {
                    if (dp[j] && words[i].substr(0, len - 1) == words[j]) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        string result = "";
        for (int i = 0; i < dp.size(); ++i) {
            if (dp[i]) {
                if (result.size() < words[i].size() || (result.size() == words[i].size() && result > words[i]))
                    result = words[i];
            }
        }
        return result;
    }
};

// solution 2: trie