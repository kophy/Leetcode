class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.size() == 0)
            return s;
        string v = s;
        reverse(v.begin(), v.end());
        int i;
        for(i = s.size(); i >= 1; --i)
            if(s.substr(0, i) == v.substr(s.size() - i, i))
                break;
        string prefix = s.substr(i);
        reverse(prefix.begin(), prefix.end());
        return prefix + s;
    }
};