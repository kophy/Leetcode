class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        string result = "";
        for (int i = 0; i < strs[0].size(); ++i) {
            for (int j = 0; j < strs.size(); ++j) {
                if (strs[0][i] != strs[j][i])
                    return result;
            }
            result += strs[0][i];
        }
        return result;
    }
};