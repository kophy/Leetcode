class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		backtracking(result, n, "", 0, 0);
		return result;
	}

private:
	void backtracking(vector<string> &result, int n, string candidate, int open, int close) {
		if (candidate.size() == 2 * n) {
			result.push_back(candidate);
			return;
		}
		if (open < n)
			backtracking(result, n, candidate + "(", open + 1, close);
		if (open > close)
			backtracking(result, n, candidate + ")", open, close + 1);
	}
};