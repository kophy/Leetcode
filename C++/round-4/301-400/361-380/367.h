class Solution {
public:
	bool isPerfectSquare(int num) {
		if (num < 0)
			return false;
		return pow((int)sqrt(num), 2) == num;
	}
};