class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0 || strs[0].size() == 0)
            return "";
        string prefix = "";
        for (int j = 0; j < strs[0].size(); ++j) {
            bool flag = true;
            
			/*  pay attention to loop variable, 
            	try to make them in alphabetic order
            */
            for (int i = 0; i < strs.size(); ++i) {
                if (j >= strs[i].size() || strs[0][j] != strs[i][j])
                    flag = false;
            }
            if (flag)
                prefix += strs[0][j];
            else
                break;
        }
        return prefix;
    }
};