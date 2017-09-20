class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> result;
		vector<string> candidate;
		backtracking(result, s, candidate, 0);
		return result;
	}

private:
	bool isPalindrome(string &s) {
		for (int i = 0, j = (int)s.size() - 1; i < j; ++i, --j)
			if (s[i] != s[j])
				return false;
		return true;
	}

	void backtracking(vector<vector<string>> &result, string &s, vector<string> &candidate, int pos) {
		if (pos == s.size()) {
			result.push_back(candidate);
			return;
		}
		for (int len = 1; pos + len <= s.size(); ++len) {
			string temp = s.substr(pos, len);
			if (!isPalindrome(temp))
				continue;
			candidate.push_back(temp);
			backtracking(result, s, candidate, pos + len);
			candidate.pop_back();
		}
	}
};