class Solution {
public:
    int strStr(string haystack, string needle) {
        int nLen = needle.length();
        int hLen = haystack.length();
        if(nLen == 0)
            return 0;

        vector<int> next(nLen, 0);
        for(int i = 1; i < nLen; ++i) {
            int j = next[i - 1];
            while(j && needle[i] != needle[j])
                j = next[j - 1];
            next[i] += j + (needle[i] == needle[j]); //the length of the matched prefix;
        }
        int i = 0, j = 0;
        while(i < hLen) {
            while(haystack[i] != needle[j] && j > 0)
                j = next[j - 1];
            if(haystack[i] == needle[j])
                ++j;
            if(j == nLen)
                return (i - j + 1);
            ++i;
        }
        return -1;
    }
};