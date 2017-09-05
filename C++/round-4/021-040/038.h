class Solution {
public:
	string countAndSay(int n) {
		string result = "1";
		for (int i = 1; i < n; ++i)
			result = countAndSay(result);
		return result;
	}

private:
	string countAndSay(string &s) {
		string t;
		int pos = 0;
		while (pos < s.size()) {
			int k = 0;
			while (pos + k < s.size() && s[pos + k] == s[pos])
				++k;
			t += to_string(k) + s[pos];
			pos += k;
		}
		return t;
	}
};