class Solution {
public:
    int titleToNumber(string s) {
        int number = 0;
        for (int i = 0; i < s.size(); ++i) {
            int d = s[i] - 'A' + 1;
            number = number * 26 + d;
        }
        return number;
    }
};