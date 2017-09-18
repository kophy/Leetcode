class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> set1(nums1.begin(), nums1.end());
		unordered_set<int> set2(nums2.begin(), nums2.end());

		vector<int> result;
		for (auto iter = set1.begin(); iter != set1.end(); ++iter)
			if (set2.find(*iter) != set2.end())
				result.push_back(*iter);
		return result;
	}
};