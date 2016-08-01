class Solution {
public:
    int titleToNumber(string s) {
        int number = 0;
        int curr = 1;
        for (int i = s.size() - 1; i >= 0; --i) {
            number += (s[i] - 'A' + 1) * curr;
            curr *= 26;
        }
        return number;
    }
};