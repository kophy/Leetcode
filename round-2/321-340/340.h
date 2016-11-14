class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> count;
        int max_length = 0;
		
		/* sliding window */
        int l = 0, r = 0;
        while (r < s.size()) {
            ++count[s[r++]];
            while (count.size() > k) {
                char d = s[l++];
                if (--count[d] == 0)
                    count.erase(d);
            }
            max_length = max(max_length, r - l);
        }
        return max_length;
    }
};