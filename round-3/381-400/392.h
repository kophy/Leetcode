class Solution {
public:
    bool isSubsequence(string s, string t) {
        return isSubsequence(s, 0, t, 0);
    }

private:
    bool isSubsequence(string &s, int sidx, string &t, int tidx) {
        if (sidx >= s.size())
            return true;
        if (tidx >= t.size())
            return false;
        while (tidx < t.size() && t[tidx] != s[sidx])
            ++tidx;
        return isSubsequence(s, sidx + 1, t, tidx + 1);
    }
};