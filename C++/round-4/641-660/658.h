class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		int index = std::lower_bound(arr.begin(), arr.end(), x) - arr.begin();
		int l = index - 1, r = index;
		while (k > 0) {
			if (l < 0 || (r < arr.size() && abs(arr[l] - x) > abs(arr[r] - x)))
				++r;
			else
				--l;
			--k;
		}
		return vector<int>(arr.begin() + l + 1, arr.begin() + r);
	}
};