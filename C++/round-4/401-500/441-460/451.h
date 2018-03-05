class Solution {
public:
	string frequencySort(string s) {
		unordered_map<char, int> count;
for (char c : s)
			++count[c];
		vector<pair<char, int>> data(count.begin(), count.end());
		sort(data.begin(), data.end(), [](pair<char, int> &a, pair<char, int> &b)->bool {
			return a.second > b.second;
		});
		ostringstream oss;
for (auto &p : data)
			oss << string(p.second, p.first);
		return oss.str();
	}
};