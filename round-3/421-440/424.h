class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.empty())
            return 0;
        int result = 1, majority = 0;
        vector<int> count(256, 0);

        int l = 0, r = 0;
        while (r < s.size()) {
            // this is not accurate majority...
            majority = max(majority, ++count[s[r]]);
            ++r;
            while (r - l > majority + k) {
                --count[s[l]];
                ++l;
            }
            result = max(result, r - l);
        }
        return result;
    }
};