class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> result;
        map<int, unordered_set<int>> pos2heights;

		for (auto &building : buildings) {
            int left = building[0];
            int right = building[1];
            int height = building[2];
            pos2heights[left].insert(height);
            pos2heights[right].insert(-height);
        }

        map<int, int> heightCount;
        int max_height = 0;
        int max_height_old = INT_MIN;

		for (auto& iter : pos2heights) {
            int pos = iter.first;
            max_height = 0;
		for (auto height : iter.second) {
                if (height > 0)
                    ++heightCount[height];
                else {
                    height = abs(height);
                    --heightCount[height];
                    if (heightCount[height] == 0)
                        heightCount.erase(height);
                }
            }
            if (!heightCount.empty())
                max_height = (*(heightCount.rbegin())).first;
            if (max_height != max_height_old)
                result.push_back(make_pair(pos, max_height));
            max_height_old = max_height;
        }
        return result;
    }
};