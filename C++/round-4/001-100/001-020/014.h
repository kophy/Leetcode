class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        if (strs.size() == 1)
            return strs[0];
		string& base = strs[0];
        for (int len = 0; len < base.size(); ++len) {
			for (int i = 1; i < strs.size(); ++i) {
				if (len >= strs[i].size() || strs[i][len] != base[len])
					return base.substr(0, len);
			}
		}
		return base;
    }
};