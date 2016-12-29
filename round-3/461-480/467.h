class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> letters(26, 0);
        int result = 0, len = 0;
        for (int i = 0; i < p.size(); ++i) {
            if (i > 0 && (p[i] - p[i - 1] + 26) % 26 != 1)
                len = 0;
            // longest string end with current character
            ++len;
            if (len > letters[p[i] - 'a']) {
                result += len - letters[p[i] - 'a'];
                letters[p[i] - 'a'] = len;
            }
        }
        return result;
    }
};