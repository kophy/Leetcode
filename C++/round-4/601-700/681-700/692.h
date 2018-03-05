/* NOT THE BEST SOLUTION */
class Solution {
public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> count;
        for (string &word : words)
            ++count[word];
        
        auto cmp = [](pair<string, int> &a, pair<string, int> &b)->bool {
            return a.second < b.second || (a.second == b.second && a.first > b.first);
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> data(cmp);
        for (auto &p : count)
            data.push(p);
        
        vector<string> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(data.top().first);
            data.pop();
        }
        return result;
    }
};