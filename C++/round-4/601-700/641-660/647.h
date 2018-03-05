class Solution {
public:
	int countSubstrings(string s) {
		int N = s.size();
		int result = 0;
		for (int i = 0; i < N; ++i) {
			// odd case
			for (int j = 0; i - j >= 0 && i + j < N && s[i - j] == s[i + j]; ++j)
				++result;
			// even case
			for (int j = 0; i - 1 - j >= 0 && i + j < N && s[i - 1 - j] == s[i + j]; ++j)
				++result;
		}
		return result;
	}
};