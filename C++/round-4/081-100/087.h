class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2)
            return true;
        vector<int> count(256, 0);
        for (char c : s1)
            ++count[c];
        for (char c : s2)
            --count[c];
        for (int i = 0; i < 256; ++i)
            if (count[i] != 0)
                return false;
        
        for (int len = 1; len < s1.size(); ++len) {
            if (isScramble(s1.substr(0, len), s2.substr(0, len)) && isScramble(s1.substr(len), s2.substr(len)))
                return true;
            if (isScramble(s1.substr(0, len), s2.substr(s2.size() - len)) && isScramble(s1.substr(len), s2.substr(0, s2.size() - len)))
                return true;
        }
        return false;
    }
};