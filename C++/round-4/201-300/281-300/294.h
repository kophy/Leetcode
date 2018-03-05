class Solution {
public:
    bool canWin(string s) {
        if (s.size() < 2)
            return false;
        unordered_set<string> cache;    // memorize all pattern can't guarantee win
        return canWin(s, cache);
    }
    
private:
    bool canWin(string &s, unordered_set<string> &cache) {
        if (cache.count(s))
            return false;
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == '+' && s[i + 1] == '+') {
                s[i] = s[i + 1] = '-';
                bool win = !canWin(s, cache);
                s[i] = s[i + 1] = '+';
                if (win)
                    return true;
            }
        }
        return false;
    }
};