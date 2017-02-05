class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return INT_MIN;

        auto cmp = [&matrix](const pair<int, int> &a, const pair<int, int> &b) {
            return matrix[a.first][a.second] > matrix[b.first][b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> data(cmp);
        for (int i = 0; i < matrix.size(); ++i)
            data.push(make_pair(i, 0));

        int result = INT_MIN;
        for (int i = 0; i < k && !data.empty(); ++i) {
            auto temp = data.top();
            data.pop();
            result = matrix[temp.first][temp.second];

            if (temp.second + 1 < matrix[0].size())
                data.push(make_pair(temp.first, temp.second + 1));
        }
        return result;
    }
};