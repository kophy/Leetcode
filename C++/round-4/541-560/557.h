class Solution {
public:
    string reverseWords(string s) {
        int begin = 0, end = begin;
        while (end < s.size()) {
            while (end < s.size() && !isspace(s[end]))
                ++end;
            reverse(s.begin() + begin, s.begin() + end);
            begin = end + 1;
            while (begin < s.size() && isspace(s[begin]))
                ++begin;
            end = begin;
        }
        return s;
    }
};