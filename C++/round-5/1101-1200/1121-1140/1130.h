class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int N = arr.size();
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for (int i = 0; i < N - 1; ++i) {
            dp[i][i + 1] = arr[i] * arr[i + 1];
        }
        for (int j = 0; j < N; ++j) {
            for (int i = j - 1; i >= 0; --i) {
                int min_cost = INT_MAX;
                for (int k = i; k < j; ++k) {
                    int left_max = *max_element(arr.begin() + i, arr.begin() + k + 1);
                    int right_max = *max_element(arr.begin() + k + 1, arr.begin() + j + 1);
                    min_cost = std::min(min_cost, dp[i][k] + dp[k + 1][j] + (left_max * right_max));
                }
                if (min_cost != INT_MAX) {
                    dp[i][j] = min_cost;
                }
            }
        }
        
        return dp[0][N - 1];
    }
};