class Solution {
public:
    bool isAdditiveNumber(string s) {
        for(int l1 = 1; l1 <= s.size() / 2; ++l1)
            for(int l2 = 1; l2 < s.size() - max(l1, l2); ++l2)
                if(check(s, 0, l1, l2))
                    return true;
        return false;
    }

private:
    bool check(const string& s, int pos, int l1, int l2) {
        int start = pos + l1 + l2;
        if(start == s.length())
            return true;
        if((s[pos]=='0' && l1 > 1) || (s[pos + l1]=='0' && l2 > 1))
            return false;

        long num1 = atol(s.substr(pos, l1).c_str());
        long num2 = atol(s.substr(pos + l1, l2).c_str());

        for(int l = max(l1, l2); l <= s.size() - start; ++l) {
            if (l > 1 && s[start] == '0')
                return false;
            long num3 = atol(s.substr(start, l).c_str());
            if(num3 > num1 + num2)
                break;
            if(num3 == num1 + num2)
                return check(s, pos + l1, l2, l);
        }
        return false;
    }
};