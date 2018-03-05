class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> count;
        for (char c : s)
            ++count[c];
        int odd = 0;
        for (auto &p : count) {
            if (p.second % 2 == 1) {
                if (++odd > 1)
                    return false;
            }
        }
        return true;
    }
};