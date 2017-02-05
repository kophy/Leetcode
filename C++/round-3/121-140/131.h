class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        if (s.size())
            partition_helper(result, path, s, 0);
        return result;
    }
    
private:
    void partition_helper(vector<vector<string>> &result, vector<string> &path, string &s, int pos) {
        if (pos == s.size()) {
            result.push_back(path);
            return;
        }
        for (int len = 1; pos + len <= s.size(); ++len) {
            string temp = s.substr(pos, len);
            if (!isPalindrome(temp))
                continue;
            path.push_back(temp);
            partition_helper(result, path, s, pos + len);
            path.pop_back();
        }
    }

    bool isPalindrome(string &s) {
        int i = 0, j = (int)s.size() - 1;
        while (i < j)
            if (s[i++] != s[j--])
                return false;
        return true;
    }
};