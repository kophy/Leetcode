class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto cmp = [&matrix](pair<int, int> a, pair<int, int> b)->bool {
            return matrix[a.first][a.second] > matrix[b.first][b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> data(cmp);
        for (int i = 0; i < matrix.size(); ++i)
            data.emplace(pair<int, int>(i, 0));
        int result;
        for (int i = 0; i < k; ++i) {
            pair<int, int> temp = data.top();
            data.pop();
            result = matrix[temp.first][temp.second];
            if (temp.second + 1 < matrix[0].size())
                data.emplace(pair<int, int>(temp.first, temp.second + 1));
        }
        return result;
    }
};