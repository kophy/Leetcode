class Solution {
public:
    string getPermutation(int n, int k) {
        --k;
		vector<int> nums(n);
		for (int i = 0; i < n; ++i)
			nums[i] = i + 1;
		
		vector<int> factorial(n, 1);
		for (int i = 1; i < n; ++i)
			factorial[i] = factorial[i - 1] * i;
		
		string result;
		for (int i = 0; i < n; ++i) {
			int factor = factorial[n - i - 1];
			int index = k / factor;
			result.push_back(nums[index] + '0');
			nums.erase(nums.begin() + index);
			k %= factor;
		}
		
		return result;
    }
};