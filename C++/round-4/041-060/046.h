class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		vector<bool> used(nums.size(), false);
		vector<int> candidate;
		backtracking(result, nums, used, candidate);
		return result;
	}

private:
	void backtracking(vector<vector<int>> &result, vector<int> &nums, vector<bool> &used, vector<int> &candidate) {
		if (candidate.size() == nums.size()) {
			result.push_back(candidate);
			return;
		}
		for (int i = 0; i < nums.size(); ++i) {
			if (used[i])
				continue;
			used[i] = true;
			candidate.push_back(nums[i]);
			backtracking(result, nums, used, candidate);
			candidate.pop_back();
			used[i] = false;
		}
	}
};