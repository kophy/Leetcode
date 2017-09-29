class Solution {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        auto cmp = [&matrix](pair<int, int> &a, pair<int, int> &b)->bool {
            return matrix[a.first][a.second] > matrix[b.first][b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> data(cmp);
        for (int i = 0; i < matrix.size(); ++i)
            data.push(make_pair(i, 0));
        int result = 0;
        for (int i = 0; i < k; ++i) {
            auto p = data.top();
            data.pop();
            result = matrix[p.first][p.second];
            
            if (p.second + 1 < matrix[p.first].size())
                data.push(make_pair(p.first, p.second + 1));
        }
        return result;
    }
};