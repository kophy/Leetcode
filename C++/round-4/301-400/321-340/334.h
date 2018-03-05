class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		int c1 = INT_MAX, c2 = INT_MAX;
		// c1 and c2 is not always valid (c1 may appear after c2).
		for (int x : nums) {
			if (x <= c1)
				c1 = x;
			else if (x <= c2)
				c2 = x;
			else
				return true;
		}
		return false;
	}
};