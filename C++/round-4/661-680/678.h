class Solution {
public:
    bool checkValidString(string s) {
        return checkValidString(s, 0, 0);
    }
    
private:
    bool checkValidString(string &s, int pos, int balance) {
        int i = pos;
        for (; i < s.size() && s[i] != '*'; ++i) {
            if (s[i] == '(')
                ++balance;
            else if (--balance < 0)
                return false;
        }
        if (i == s.size())
            return balance == 0;
        else
            return checkValidString(s, i + 1, balance + 1) || checkValidString(s, i + 1, balance - 1) || checkValidString(s, i + 1, balance);
    }
};