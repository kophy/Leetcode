class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        for (char c : s)
            ++count[c];
        int result = 0;
        for (auto &p : count) {
            if (result % 2 == 1 && p.second % 2 == 1)
                result += p.second - 1;
            else
                result += p.second;
        }
        return result;
    }
};