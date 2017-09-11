class Solution {
public:
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		unordered_map<string, int> map1, map2;
		for (int i = 0; i < list1.size(); ++i)
			map1[list1[i]] = i;
		for (int i = 0; i < list2.size(); ++i)
			map2[list2[i]] = i;

		unordered_map<string, int> common_map;
		for (auto iter = map1.begin(); iter != map1.end(); ++iter) {
			if (map2.find(iter->first) == map2.end())
				continue;
			common_map[iter->first] = iter->second + map2[iter->first];
		}
		vector<pair<string, int>> common_list(common_map.begin(), common_map.end());
		sort(common_list.begin(), common_list.end(), [](pair<string, int> &p, pair<string, int> &q)->bool {
			return p.second < q.second;
		});
		vector<string> result;
		for (int i = 0; i < common_list.size() && common_list[i].second == common_list[0].second; ++i)
			result.push_back(common_list[i].first);
		return result;
	}
};