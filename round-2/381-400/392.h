class Solution {
public:
    bool isSubsequence(string s, string t) {
        return match(s, 0, t, 0);
    }

private:
    bool match(string &s, int s_index, string &t, int t_index) {
        if (s_index == s.size())
            return true;
        if (t_index == t.size())
            return false;

        // match first appearance
        while (t_index < t.size() && t[t_index] != s[s_index]) ++ t_index;
        if (t_index == t.size())
            return false;
        else
            return match(s, s_index + 1, t, t_index + 1);
    }
};