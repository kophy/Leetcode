class Solution {
public:
	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
		sort(people.begin(), people.end(), [](pair<int, int> &a, pair<int, int> &b) -> bool {
			return a.first > b.first || (a.first == b.first && a.second < b.second);
		});
		vector<pair<int, int>> result;
		for (auto person : people)
			result.insert(result.begin() + person.second, person);
		return result;
	}
};