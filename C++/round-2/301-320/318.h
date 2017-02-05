class Solution {
public:
    int maxProduct(vector<string> &words) {
        vector<int> hashtags(words.size(), 0);
        generateHashTag(words, hashtags);

        int max_product = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if ((hashtags[i] & hashtags[j]) == 0)
                    max_product = max(max_product, (int)words[i].size() * (int)words[j].size());
            }
        }
        return max_product;
    }

private:
    void generateHashTag(vector<string> &words, vector<int> &hashtags) {
        for (int i = 0; i < words.size(); ++i)
            for (int j = 0; j < words[i].size(); ++j)
                hashtags[i] |= 1 << (words[i][j] - 'a');
    }
};