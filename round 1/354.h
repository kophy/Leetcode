class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int size = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](pair<int, int> a, pair<int, int>b) -> bool {
            return a.first < b.first || (a.first == b.first && a.second > b.second);
        });

        vector<int> collector;
		for(auto& pair: envelopes) {
            auto iter = lower_bound(collector.begin(), collector.end(), pair.second);
            if(iter == collector.end())
                collector.push_back(pair.second);
            else
                *iter = min(*iter, pair.second);
        }
        return collector.size();
    }
};