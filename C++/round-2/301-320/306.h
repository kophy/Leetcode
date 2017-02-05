class Solution {
public:
    bool isAdditiveNumber(string s) {
        for(int len1 = 1; len1 <= s.size() / 2; ++len1) {
            if (len1 > 1 && s[0] == '0')
                break;
            for(int len2 = 1; len2 < s.size() - max(len1, len2); ++len2) {
                if (len2 > 1 && s[len1] == '0')
                    break;
                long num1 = stol(s.substr(0, len1)), num2 = stol(s.substr(len1, len2));

                // use valid num1 & num2 to start recursion
                if (isAdditive(s, len1 + len2, num1, num2))
                    return true;
            }
        }
        return false;
    }

private:
    bool isAdditive(string &s, int pos, long num1, long num2) {
        if (pos == s.length())
            return true;

        long num3 = num1 + num2;
        string s3 = to_string(num3);
        int len3 = s3.size();

        // check whether num3 illegal
        if (s[pos] == '0' && len3 > 1)
            return false;
        // check whether recursion fails
        if (s.substr(pos, len3) != s3)
            return false;

        // recursion
        return isAdditive(s, pos + len3, num2, num3);
    }
};