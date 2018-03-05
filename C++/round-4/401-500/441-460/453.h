class Solution {
public:
	int minMoves(vector<int>& nums) {
		if (nums.size() <= 1)
			return 0;
		int minimum = INT_MAX;
		for (int &num : nums)
			minimum = min(minimum, num);
		int moves = 0;
		for (int &num : nums)
			moves += num - minimum;
		return moves;
	}
};