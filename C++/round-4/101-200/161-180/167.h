class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int l = 0, r = (int)numbers.size() - 1;
		while (l < r) {
			int sum = numbers[l] + numbers[r];
			if (sum == target)
				return {l + 1, r + 1};
			else if (sum < target)
				++l;
			else
				--r;
		}
		return {0, 0};
	}
};