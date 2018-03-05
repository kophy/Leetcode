class Solution {
public:
	bool isOneEditDistance(string s, string t) {
		// 0. handle deletion as insertion
		if (s.size() > t.size())
			return isOneEditDistance(t, s);
		if (s.size() + 1 < t.size())
			return false;

		// 1. replace
		if (s.size() == t.size()) {
			int count = 0;
			for (int i = 0; i < s.size(); ++i)
				if (s[i] != t[i])
					++count;
			return count == 1;
		}
		// 2. insertion
		int i = 0, j = 0, skip = 0;
		while (i < s.size() && j < t.size()) {
			if (s[i] == t[j]) {
				++i;
				++j;
			} else {
				++j;
				if (++skip > 1)
					return false;
			}
		}
		return true;
	}
};