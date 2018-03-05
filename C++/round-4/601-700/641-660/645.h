class Solution {
public:
	vector<int> findErrorNums(vector<int> &nums) {
		int N = nums.size();
		unordered_set<int> visited;

		int expect = N * (N + 1) / 2;
		int actual = accumulate(nums.begin(), nums.end(), 0);
		for (int num : nums ) {
			if (visited.count(num))
				return {num, expect - actual + num};
			visited.insert(num);
		}
		return {-1, -1};
	}
};