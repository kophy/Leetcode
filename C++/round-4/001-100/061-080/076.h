class Solution {
public:
	string minWindow(string s, string t) {
		// Keeps two info for each window.
		vector<int> count(256, 0);
for (char c : t)
			--count[c];
		int unmatched = t.size();

		int begin = 0, end = 0;
		int min_begin = -1, min_length = s.size() + 1;
		for (; end < s.size(); ++end) {
			// Use umatched count to avoid check every elements in window.
			if (count[s[end]] < 0)
				--unmatched;
			++count[s[end]];

			if (unmatched == 0) {
				// Shrink window only it contains all characters in t.
				while (count[s[begin]] >= 1) {
					--count[s[begin]];
					++begin;
				}
				if (min_length >= end - begin + 1) {
					min_begin = begin;
					min_length = end - begin + 1;
				}
			}
		}
		return min_begin < 0? "" : s.substr(min_begin, min_length);
	}
};