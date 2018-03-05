// version 1: O(N) use monotonic property
class Solution {
public:
	int characterReplacement(string s, int k) {
		if (s.empty())
			return 0;
		int result = 1, majority = 0;
		vector<int> count(256, 0);

		int l = 0, r = 0;
		while (r < s.size()) {
			majority = max(majority, ++count[s[r]]);
			++r;
			if (r - l > majority + k) {
				--count[s[l]];
				++l;
			}
			result = max(result, r - l);
		}
		return result;
	}
};

// version 2: O(N^2) better framework
class Solution {
public:
	int characterReplacement(string s, int k) {
		if (s.size() <= k)
			return s.size();
		int max_length = 1;

		// sliding window
		for (int pos = 0; pos + max_length <= s.size();) {
			int count[26] = {0};
			int max_index = 0;

			int start = pos, end = pos;
			for (; end < s.size(); ++end) {
				int index = s[end] - 'A';
				++count[index];
				if (count[index] > count[max_index])
					max_index = index;

				// accelerate property check
				if (end - start + 1 <= count[max_index] + k)
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