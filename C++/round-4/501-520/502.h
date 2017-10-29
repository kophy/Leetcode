class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        vector<pair<int, int>> projects;
        for (int i = 0; i < Profits.size(); ++i)
            projects.push_back(make_pair(Profits[i], Capital[i]));
        sort(projects.begin(), projects.end(), [](pair<int, int> &a, pair<int, int> &b)->bool {
           return a.second < b.second; 
        });
        
        priority_queue<int, vector<int>, less<int>> data;
        int pos = 0;
        for (int i = 0; i < k; ++i) {
            for (; pos < projects.size() && projects[pos].second <= W; ++pos)
                data.push(projects[pos].first);
            if (data.empty())
                break;
            W += data.top();
            data.pop();
        }
        return W;
    }
};