class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		vector<int> result(digits.size() + 1, 0);
		int i = digits.size() - 1, k = result.size() - 1, carry = 1;
		while (i >= 0 || carry != 0) {
			int sum = carry;
			if (i >= 0)
				sum += digits[i--];
			result[k--] = sum % 10;
			carry = sum / 10;
		}
		if (result[0] == 0)
			result.erase(result.begin());
		return result;
	}
};