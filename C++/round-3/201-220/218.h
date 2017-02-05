class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> data;
        for (auto building : buildings) {
            data.push_back(make_pair(building[0], building[2]));
            data.push_back(make_pair(building[1], -building[2]));
        }
        sort(data.begin(), data.end(), [](pair<int, int> &a, pair<int, int> &b) -> bool {
            return a.first < b.first || (a.first == b.first && a.second > b.second);
        });
        vector<pair<int, int>> result;
        multiset<int> window;
        window.insert(0);
        int last = 0;
        for (auto d : data) {
            if (d.second > 0)
                window.insert(d.second);
            if (d.second < 0)
                window.erase(window.find(-d.second));
            int curr = *(window.rbegin());
            if (curr != last) {
                if (result.size() && result.back().first == d.first)
                    break;
                result.push_back(make_pair(d.first, curr));
            }
            last = curr;
        }
        return result;
    }
};