class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> count(256, 0);
        int max_length = 0;
		for (int begin = 0, end = 0; end < s.size(); ++end) {
			++count[s[end]];
			while (count[s[end]] > 1) {
				--count[s[begin]];
				++begin;
			}
			max_length = max(max_length, end - begin + 1);
		}
		return max_length;
    }
};