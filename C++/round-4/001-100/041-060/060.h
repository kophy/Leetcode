class Solution {
public:
	string getPermutation(int n, int k) {
		// most tricky part: k == n
		--k;
		vector<char> candidates;
		for (int i = 1; i <= n; ++i)
			candidates.push_back('0' + i);

		vector<int> factorial(n + 1, 1);
		for (int i = 2; i <= n; ++i)
			factorial[i] = factorial[i - 1] * i;

		string result;
		while (n > 0) {
			int idx = k / factorial[n - 1];
			k %= factorial[n - 1];

			result.push_back(candidates[idx]);
			candidates.erase(candidates.begin() + idx);
			--n;
		}
		return result;
	}
};