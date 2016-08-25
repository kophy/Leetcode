class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        map<char, int> count;
        for (int i = 0; i < s.size(); ++i)
            ++count[s[i]];
        for (int j = 0; j < t.size(); ++j) {
            if (count.find(t[j]) == count.end() || count[t[j]] <= 0)
                return false;
            else
                --count[t[j]];
        }
        return true;
    }
};