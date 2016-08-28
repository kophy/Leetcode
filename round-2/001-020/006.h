class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        string result = "";
        int cycle = 2 * (numRows - 1);
        for (int i = 0; i < numRows; ++i) {
            int delta = 2 * (numRows - i - 1);
            for (int j = i; j < s.size(); j += cycle) {
                result += s[j];

                /* when adding the character, we must ensure j + delta < s.size() */
                if (i != 0 && i != numRows - 1 && j + delta < s.size())
                    result += s[j + delta];
            }
        }
        return result;
    }
};