class Solution {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        auto cmp = [&matrix](pair<int, int> &a, pair<int, int> &b) -> bool {
            return matrix[a.first][a.second] > matrix[b.first][b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> data(cmp);

        for (int i = 0; i < matrix.size(); ++i)
            data.push(make_pair(i, 0));

        int result = 0;
        for (int i = 0; i < k; ++i) {
            auto temp = data.top();
            data.pop();
            result = matrix[temp.first][temp.second];
            if (temp.second + 1 < matrix[0].size())
                data.push(make_pair(temp.first, temp.second + 1));
        }
        return result;
    }
};