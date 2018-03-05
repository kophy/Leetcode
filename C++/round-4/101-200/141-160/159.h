class Solution {
public:
	int lengthOfLongestSubstringTwoDistinct(string s) {
		int max_length = 0;
		unordered_map<char, int> count;
		int begin = 0, end = 0;
		for (; end < s.size(); ++end) {
			++count[s[end]];
			while (count.size() > 2) {
				--count[s[begin]];
				if (count[s[begin]] == 0)
					count.erase(s[begin]);
				++begin;
			}
			max_length = max(max_length, end - begin + 1);
		}
		return max_length;
	}
};