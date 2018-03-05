class Solution {
public:
	string findLongestWord(string s, vector<string>& d) {
		string result = "";
		for (string &t : d) {
			if (s.size() < t.size() || !isSubsequence(s, t))
				continue;
			if (result.size() < t.size() || (result.size() == t.size() && result > t))
				result = t;
		}
		return result;
	}

private:
	bool isSubsequence(string &s, string &t) {
		int i = 0, j = 0;
		while (i < s.size() && j < t.size()) {
			if (s[i] == t[j])
				++j;
			++i;
		}
		return j == t.size();
	}
};