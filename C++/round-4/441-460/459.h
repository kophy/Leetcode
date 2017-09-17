class Solution {
public:
	bool repeatedSubstringPattern(string str) {
		if (str.size() <= 1)
			return false;
		int N = str.size();
		for (int len = N / 2; len > 0; --len) {
			if (N % len != 0)
				continue;
			string pattern = str.substr(0, len);
			if (isRepeatedPattern(str, pattern))
				return true;
		}
		return false;
	}

private:
	bool isRepeatedPattern(string &str, string &pattern) {
		int k = pattern.size();
		for (int i = k; i < str.size(); ++i)
			if (str[i] != pattern[i % k])
				return false;
		return true;
	}
};