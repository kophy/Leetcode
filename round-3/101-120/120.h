class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty())
            return 0;
        for (int i = 1; i < triangle.size(); ++i) {
            triangle[i][0] += triangle[i - 1][0];
            triangle[i][i] += triangle[i - 1][i - 1];
            for (int j = 1; j < i; ++j)
                triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
        }
        int N = triangle.size(), result = INT_MAX;
        for (int j = 0; j < triangle[N - 1].size(); ++j)
            result = min(result, triangle[N - 1][j]);
        return result;
    }
};