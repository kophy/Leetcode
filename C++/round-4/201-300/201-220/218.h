class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>> &buildings) {
        // 1. preparation array for sliding window
        vector<pair<int, int>> diff;
		for (auto &building : buildings) {
			diff.push_back(make_pair(building[0], building[2]));
			diff.push_back(make_pair(building[1], -building[2]));
		}
        sort(diff.begin(), diff.end(), [](pair<int, int> &a, pair<int, int> &b)->bool {
            return a.first < b.first || (a.first == b.first && a.second > b.second);
        });
		
        // 2. set up window
		multiset<int> window;
		window.insert(0);
		int last_height = 0;
		
        // 3. slide and update skyline when height changes
		vector<pair<int, int>> result;
		int pos = 0;
		while (pos < diff.size()) {
			int edge = diff[pos].first;
			while (pos < diff.size() && diff[pos].first == edge) {
				if (diff[pos].second > 0)
					window.insert(diff[pos].second);
				if (diff[pos].second < 0)
					window.erase(window.find(-diff[pos].second));
				++pos;
			}
			int curr_height = *(window.rbegin());
			if (curr_height != last_height) {
				result.push_back(make_pair(edge, curr_height));
				last_height = curr_height;
			}
		}
		return result;
    }
};