class Solution {
public:
	string findContestMatch(int n) {
		vector<string> matches;
		for (int i = 1; i <= n; ++i)
			matches.push_back(to_string(i));
		while (matches.size() > 1)
			matches = getNextRound(matches);
		return matches[0];
	}

private:
	vector<string> getNextRound(vector<string> &matches) {
		vector<string> result;
		for (int i = 0; i < matches.size() / 2; ++i)
			result.push_back("(" + matches[i] + "," + matches[matches.size() - i - 1] + ")");
		return result;
	}
};