class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2)
            return s;
        int start = 0, len = 1;
        for (int i = 0; i < s.size();) {
            int j = i, k = i;
            while (k < s.size() - 1 && s[k + 1] == s[k])
                ++k;
            i = k + 1;
            while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1]) {
                ++k;
                --j;
            }
            if (k - j + 1 > len) {
                start = j;
                len = k - j + 1;
            }
        }
        return s.substr(start, len);
    }
};