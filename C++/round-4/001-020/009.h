class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		for (int i = 0, j = countDigits(x) - 1; i < j; ++i, --j)
			if (findKthDigit(x, i) != findKthDigit(x, j))
				return false;
		return true;
	}

private:
	int countDigits(int x) {
		int count = 0;
		for (; x > 0; x /= 10)
			++count;
		return count;
	}

	int findKthDigit(int x, int k) {
		return (x / (int)pow(10, k)) % 10;
	}
};