class Solution {
public:
    int longestSubstring(string s, int k) {
        return longestSubstring_help(s, k, 0, s.size() - 1);
    }

private:
    /* divide & conquer */
    int longestSubstring_help(string &s, int k, int b, int e) {
        int len = e - b + 1;
        if (len == 0 || len < k)
            return 0;
        map<char, int> count;
        for (int i = b; i <= e; ++i)
            ++count[s[i]];

        int pivot = b;
        while (pivot <= e && count[s[pivot]] >= k)
            ++pivot;

        // s[pivot] won't be in the final string -- it's a broken point!
        // longest substring appears either in its left part or in its right part
        if (pivot > e)
            return len;
        else
            return max(longestSubstring_help(s, k, b, pivot - 1),
                       longestSubstring_help(s, k, pivot + 1, e));
    }
};