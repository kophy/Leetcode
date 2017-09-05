class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		vector<bool> used(n, false);
		vector<int> candidate;
		backtracking(result, n, k, used, 0, candidate);
		return result;
	}

private:
	// In combination, scan pointer can't go back (as against to permutation).
	void backtracking(vector<vector<int>> &result, int n, int k, vector<bool> &used, int pos, vector<int> &candidate) {
		if (candidate.size() == k) {
			result.push_back(candidate);
			return;
		}
		for (int i = pos; i < n; ++i) {
			if (!used[i]) {
				used[i] = true;
				candidate.push_back(i + 1);
				backtracking(result, n, k, used, i + 1, candidate);
				candidate.pop_back();
				used[i] = false;
			}
		}
	}
};