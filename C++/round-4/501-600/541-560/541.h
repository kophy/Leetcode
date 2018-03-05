class Solution {
public:
	string reverseStr(string s, int k) {
		int pos = 0;
		while (pos < s.size()) {
			int len = min(k, (int)s.size() - pos);
			reverse(s.begin() + pos, s.begin() + pos + len);
			pos += 2 * k;
		}
		return s;
	}
};