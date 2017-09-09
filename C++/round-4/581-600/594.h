class Solution {
public:
	int findLHS(vector<int>& nums) {
		unordered_map<int, int> count;
for (int num : nums)
			++count[num];

		vector<pair<int, int>> data(count.begin(), count.end());
		sort(data.begin(), data.end(), [](pair<int, int> &p, pair<int, int> &q)->bool {
			return p.first < q.first;
		});

		int lhs = 0;
		for (int i = 0; i < (int)data.size() - 1; ++i) {
			if (data[i].first + 1 != data[i + 1].first)
				continue;
			lhs = max(lhs, data[i].second + data[i + 1].second);
		}
		return lhs;
	}
};