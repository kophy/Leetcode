class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](pair<int, int> &a, pair<int, int> &b) -> bool {
            return a.first < b.first || (a.first == b.first && a.second > b.second);
        });
        vector<int> result;
        for (auto e : envelopes) {
            auto iter = lower_bound(result.begin(), result.end(), e.second);
            if (iter == result.end())
                result.push_back(e.second);
            else
                *iter = e.second;
        }
        return result.size();
    }
};