class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
for (int num : nums)
            ++count[num];
        auto cmp = [](pair<int, int> &a, pair<int, int> &b) -> bool {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> data(cmp);
        for (auto iter = count.begin(); iter != count.end(); ++iter) {
            if (data.size() < k)
                data.push(make_pair(iter->first, iter->second));
            else if (iter->second > data.top().second) {
                data.pop();
                data.push(make_pair(iter->first, iter->second));
            }
        }
        vector<int> result;
        while (!data.empty()) {
            result.push_back(data.top().first);
            data.pop();
        }
        return result;
    }
};