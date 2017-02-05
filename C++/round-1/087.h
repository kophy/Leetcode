class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        if (s1 == s2)
            return true;
        vector<int> count(26, 0);
        for (int i = 0; i < s1.size(); ++i)
            ++count[s1[i] - 'a'], --count[s2[i] - 'a'];
        for (int i = 0; i < 26; ++i)
            if (count[i])
                return false;
        for (int i = 1; i < s1.size(); ++i) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                    isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if (isScramble(s1.substr(0, i), s2.substr(s2.size() - i)) &&
                    isScramble(s1.substr(i), s2.substr(0, s2.size() - i)))
                return true;
        }
        return false;
    }
};