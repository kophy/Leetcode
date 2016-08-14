class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        partition_help(result, s, 0, vector<string>());
        return result;
    }

private:
    void partition_help(vector<vector<string>> &result, string &s, int pos, vector<string> temp) {
        if (pos == s.size()) {
            result.push_back(temp);
            return;
        }
        for(int i = 0; pos + i < s.size(); ++i) {
            if(isPalindrome(s, pos, pos + i)) {
                temp.push_back(s.substr(pos, i + 1));
                partition_help(result, s, pos + i + 1, temp);
                temp.pop_back();
            }
        }
    }

    bool isPalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
};