class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        partition_help(result, s, path, 0);
        return result;
    }

private:
    void partition_help(vector<vector<string>> &result, string &s, vector<string> &path, int pos) {
        if (pos == s.size())
            result.push_back(path);
        for (int len = 1; pos + len <= s.size(); ++len) {
            string temp = s.substr(pos, len);
            if (isPalindrom(temp)) {
                path.push_back(temp);
                partition_help(result, s, path, pos + len);
                path.pop_back();
            }
        }
    }

    bool isPalindrom(string &s) {
        int i = 0, j = s.size() - 1;
        while (i < j)
            if (s[i++] != s[j--])
                return false;
        return true;
    }
};