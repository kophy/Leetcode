class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> unique_nums(nums.begin(), nums.end());
		return unique_nums.size() != nums.size();
	}
};