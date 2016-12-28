class Solution {
public:
    int maxProduct(vector<string> &words) {
        vector<int> pattern(words.size(), 0);
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words[i].size(); ++j)
                pattern[i] |= 1 << (words[i][j] - 'a');
        }
        int result = 0;
        for (int i = 0; i < words.size(); ++i)
            for (int j = i + 1; j < words.size(); ++j) {
                if ((int)(pattern[i] & pattern[j]) == 0)
                    result = max(result, (int)words[i].size() * (int)words[j].size());
            }
        return result;
    }
};