class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = 1; i < triangle.size(); ++i) {
            triangle[i][0] += triangle[i - 1][0];
            triangle[i][i] += triangle[i - 1][i - 1];
            for (int j = 1; j < i; ++j)
                triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
        }
        return *min_element(triangle.back().begin(), triangle.back().end());
    }
};