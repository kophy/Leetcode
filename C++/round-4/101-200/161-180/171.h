class Solution {
public:
    int titleToNumber(string s) {
        int number = 0;
        for (char c : s)
            number = number * 26 + c - 'A' + 1;
        return number;
    }
};