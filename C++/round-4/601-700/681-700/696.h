class Solution {
public:
    int countBinarySubstrings(string s) {
        int result = 0;
        int last = 0, curr = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1])
                ++curr;
            else {
                last = curr;
                curr = 1;
            }
            if (last >= curr)
                ++result;
        }
        return result;
    }
};