class Solution {
public:
	bool isAnagram(string s, string t) {
		vector<int> count(256, 0);
for (char c : s)
			++count[c];
for (char c : t)
			--count[c];
		for (int i = 0; i < 256; ++i)
			if (count[i] != 0)
				return false;
		return true;
	}
};