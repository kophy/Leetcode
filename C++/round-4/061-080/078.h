class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> result;
		result.push_back(vector<int>());
		for (int num : nums) {
			for (int i = result.size() - 1; i >= 0; --i) {
				vector<int> temp = result[i];
				temp.push_back(num);
				result.push_back(temp);
			}
		}
		return result;
	}
};