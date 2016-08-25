class Solution {
public:
    string reverseString(string s) {
        for (int i = 0; i < s.size() / 2; ++i) {
            char temp = s[i];
            s[i] = s[s.size() - i - 1];
            s[s.size() - i - 1] = temp;
        }
        return s;
    }
};