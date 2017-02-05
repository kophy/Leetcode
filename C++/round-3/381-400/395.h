class Solution {
public:
    int longestSubstring(string s, int k) {
        int max_length = 0;
        int start = 0;
        while (start + k <= s.size()) {
            int count[26] = {0};
            bitset<26> mask(0);
            for (int i = start; i < s.size(); ++i) {
                ++count[s[i] - 'a'];
                mask[s[i] - 'a'] = (count[s[i] - 'a'] >= k)? 0 : 1;
                if (mask.none())
                    max_length = max(max_length, i - start + 1);
            }
            /* skip same beginning character */
            int temp = start + 1;
            while (temp + k <= s.size() && s[temp] == s[start])
                ++temp;
            start = temp;
        }
        return max_length;
    }
};