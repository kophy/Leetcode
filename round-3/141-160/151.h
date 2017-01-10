class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int i = 0, j = 0;
        while (i < s.size()) {
            while (i < s.size() && isspace(s[i]))
                s.erase(s.begin() + i);
            if (i < s.size()) {
                j = i;
                while (j < s.size() && !isspace(s[j]))
                    ++j;
                reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            }
        }
        if (!s.empty() && s.back() == ' ')
            s.pop_back();
    }
};