class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> count;
        for (int i = 0; i < nums.size(); ++i)
            ++count[nums[i]];
        auto cmp = [](pair<int, int> &a, pair<int, int> &b) {
            return a.second < b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> data(cmp);
        for (auto iter = count.begin(); iter != count.end(); ++iter) {
            data.emplace(pair<int, int>(iter->first, iter->second));
        }
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            auto temp = data.top();
            data.pop();
            result.push_back(temp.first);
        }
        return result;
    }
};