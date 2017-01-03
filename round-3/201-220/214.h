class Solution {
public:
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());

        for (int i = s.size(); i > 0; --i)
            if (s.substr(0, i) == r.substr(r.size() - i))
                return r.substr(0, r.size() - i) + s;
        return r;
    }
};