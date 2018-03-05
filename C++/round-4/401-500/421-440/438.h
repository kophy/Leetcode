class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> sv(256, 0), pv(256, 0);
for (char c : p)
			++pv[c];
		int k = p.size();

		vector<int> result;
		for (int i = 0; i < s.size(); ++i) {
			++sv[s[i]];
			if (i - k >= 0)
				--sv[s[i - k]];
			if (sv == pv)
				result.push_back(i - k + 1);
		}
		return result;
	}
};