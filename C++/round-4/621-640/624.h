class Solution {
public:
	int maxDistance(vector<vector<int>> &arrays) {
		int result = INT_MIN;
		int curr_min = arrays[0][0], curr_max = arrays[0].back();
		for (int i = 1; i < arrays.size(); ++i) {
			result = max(result, max(abs(arrays[i][0] - curr_max), abs(arrays[i].back() - curr_min)));
			curr_min = min(curr_min, arrays[i][0]);
			curr_max = max(curr_max, arrays[i].back());
		}
		return result;
	}
};