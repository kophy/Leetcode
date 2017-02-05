class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.size() - 1;
        while(isspace(s[end]))
            --end;
        int len = 0;
        while(end >= 0 && isalpha(s[end])) {
            --end;
            ++len;
        }
        return len;
    }
};