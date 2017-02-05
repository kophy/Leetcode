class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int start = 0, end = 0;

        while (start < s.size()) {
            while (start < s.size() && isspace(s[start]))
                s.erase(s.begin() + start);
            end = start;
            while (end < s.size() && !isspace(s[end]))
                ++end;
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
        }
        if(!s.empty() && s[s.size()-1]==' ')
            s.resize(s.size() - 1);
    }
};