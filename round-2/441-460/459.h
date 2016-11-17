class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        for (int i = str.size() / 2; i > 0; --i)
            if (str.size() % i == 0 && repeatWithPattern(str, i))
                return true;
        return false;
    }

private:
    bool repeatWithPattern(string &str, int len) {
        string pattern = str.substr(0, len);
        for (int i = len; i + len <= str.size(); i += len)
            if (str.substr(i, len) != pattern)
                return false;
        return true;
    }
};