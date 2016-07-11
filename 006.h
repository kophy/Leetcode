class Solution {
public:
    string convert(string s, int numRows) {
        if (s.size() == 0 || numRows < 2)
            return s;

        string result = "";
        for (int i = 0; i < numRows; ++i) {
            int cycle = 2 * (numRows - 1);
            int delta = (cycle - 2 * i) % cycle;

            int j = i;
            while (j < s.size()) {
                result.push_back(s[j]);
                if (delta && j + delta < s.size())
                    result.push_back(s[j + delta]);
                j += cycle;
            }

        }

        return result;
    }
};