class Solution {
public:
    int longestSubstring(string s, int k) {
        int max_length = 0;

		// sliding window
        for (int pos = 0; pos + k <= s.size();) {
            int count[26] = {0};
            bitset<26> mask(0);
            
            int start = pos, end = pos;
            for (; end < s.size(); ++end) {
                ++count[s[end] - 'a'];
                mask[s[end] - 'a'] = (count[s[end] - 'a'] >= k)? 0 : 1;
				
				// accelerate property check
                if (mask.none())
                    max_length = max(max_length, end - start + 1);
            }

            // skip same character
            int new_pos = pos;
            while (new_pos + k <= s.size() && s[new_pos] == s[pos])
                ++new_pos;
            pos = new_pos;
        }
        return max_length;
    }
};