class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<bitset<26>> letters(words.size());
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                letters[i].set(words[i][j] - 'a');
            }
        }
        int max_product = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                bool flag = true;
                if (!(letters[i].to_ulong() & letters[j].to_ulong()))
                    max_product = max(max_product, (int)words[i].size() * (int)words[j].size());
            }
        }
        return max_product;
    }
};