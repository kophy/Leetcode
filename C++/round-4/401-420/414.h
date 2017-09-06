class Solution {
public:
	int thirdMax(vector<int>& nums) {
		long c1 = LONG_MIN, c2 = LONG_MIN, c3 = LONG_MIN;
		for (int &num : nums) {
			if (num == c1 || num == c2 || num == c3)
				continue;
			if (num > c1) {
				c3 = c2;
				c2 = c1;
				c1 = num;
			} else if (num > c2) {
				c3 = c2;
				c2 = num;
			} else if (num > c3) {
				c3 = num;
			}
		}
		return (c3 == LONG_MIN)? c1 : c3;
	}
};