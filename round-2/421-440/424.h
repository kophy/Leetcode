class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[256] = {0};
        int l = 0, r = 0, majority = 0, result = 0;
        while (r < s.size()) {
            // choose majority character as target
            majority = max(majority, ++count[s[r++]]);
            // shrink window
            if (r - l - majority > k)
                --count[s[l++]];
            // update max length
            result = max(result, r - l);
        }
        return result;
    }
};