class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1)
            return s.size();

        int begin = 0, len = 0;
        int max_len = 0;
        map<int, int> index;

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            /*  s.substr(begin, len) is the current substring, so:
            	1. index.find(c) == index.end() -- the character has not appeared yet
            	2. index[c] < begin	    	    -- the character is not in current substring
            */
            if (index.find(c) == index.end() || index[c] < begin) {
                index[c] = i;
                ++len;
                max_len = max(max_len, len);
            }
            /*   character c appears again.
            	 Update begin and len to cut the prefix string away from current substring.
            */
            else {
                begin = index[c] + 1;
                len = i - index[c];
                index[c] = i;
            }
        }
        return max_len;
    }
};