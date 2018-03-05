class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> count;
	for (int &num : nums)
			++count[num];
		auto cmp = [](pair<int, int> &a, pair<int, int> &b)->bool {
			return a.second > b.second;
		};
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> data(cmp);
	for (auto &p : count) {
			if (data.size() < k || data.top().second < p.second)
				data.push(p);
			if (data.size() > k)
				data.pop();
		}
		vector<int> result;
		while (!data.empty()) {
			result.push_back(data.top().first);
			data.pop();
		}
		return result;
	}
};