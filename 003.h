class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (!s.size())
            return 0;

        int max_length = 1;

        for (int i = 0; i < s.size(); ++i) {
            vector<int> index(256, -1);
            index[s[i]] = i;

            for (int j = i + 1; j <= s.size(); ++j) {
                if (j == s.size() || index[s[j]] >= 0) {
                    int length = j - i;
                    max_length = max_length > length? max_length : length;
                    break;
                } else
                    index[s[j]] = j;
            }
        }
        return max_length;
    }
};